#define VC_EXTRALEAN 1
#define WIN32_EXTRA_LEAN 1
#define LEAN_AND_MEAN 1
#include <windows.h>

struct				t_image
{
	u32				width;
	u32				height;
	u32				*pixels;
};

u8	rgba32_to_ansi(u32 color)
{
	u8		*rgb;

	rgb = (unsigned char*)&color;
	// we use the extended greyscale palette here, with the exception of
	// black and white. normal palette only has 4 greyscale shades.
	if (rgb[3] == rgb[2] && rgb[2] == rgb[1])
	{
		if (rgb[3] < 8)
			return 16;
		if (rgb[3] > 248)
			return 231;
		return (u8)round((((float)rgb[3] - 8.0) / 247.0) * 24) + 232;
	}
	u8 ansi = 16
		+ (36 * (u32)round((float)rgb[3] / 255.0 * 5))
		+ (6 * (u32)round((float)rgb[2] / 255.0 * 5))
		+ (u32)round((float)rgb[1] / 255.0 * 5);
	return (ansi);
}

void	clear_console(HANDLE hConsole)
{
	COORD coordScreen = {0};
	SetConsoleCursorPosition(hConsole, coordScreen);
}

ivec2	get_console_size(void)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	ivec2 res;
	// div by 2 because using 2 ascii chars for square pixels
	res.x = (i32)csbi.srWindow.Right / 2;
	res.y = (i32)csbi.srWindow.Bottom;
	return (res);
}

void	image_to_console(t_image *image)
{
	char	*brightness = ".'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	char	buf[10000];
	int		i = 0;

	for (int y = 0; y < image->height; y++)
	{
		for (int x = 0; x < image->width; x++)
		{
			float b = rgba32_brightness(image->pixels[x + y * image->width]);
			u32 idx = ((u32)strlen(brightness) - 1) * b;
			char c1 = brightness[idx];
			char c2 = brightness[idx + 1];

			char str[20];
			sprintf(str, "\e[48;5;%dm%c%c", rgba32_to_ansi(image->pixels[x + y * image->width]), c1, c2);
			size_t len = strlen(str);
			memcpy(&buf[i], str, len);
			i += len;
		}
		buf[i] = '\n';
		i++;
	}
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD byteswritten;
	WriteConsole(h, buf, i, &byteswritten, NULL);
}

void	console_render(t_image *image)
{
	ivec2 size = get_console_size();
	t_image scaled_img = image_scale(&image, size.x, size.y);
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	clear_console(console);
	image_to_console(&scaled_img);
	free_image(&scaled_img)
}
