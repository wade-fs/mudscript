inherit ROOM;

void create()
{
	set("short","地下通道");
	set("long",@LONG
    地上有許多已經殘缺不全的骨骸，彷彿一堆散沙的被隨意丟棄於
地上，地上血跡斑斑，鮮血與腐肉的惡臭瀰漫整個空間，令人十分的
不舒服，你只想趕快離開這！
LONG);
	set("exits",([
		"north":__DIR__"u11",
	]));
	set("no_transmit",1);
	setup();
}
