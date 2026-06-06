inherit ROOM;
void create()
{
set("short", "海神坊");
set("long",@LONG
這該說是一個房間、還是一個空間，四周向外無限延伸，完全看不到
邊界，一片白茫茫的景象，彷彿置身於茫茫大霧之中，約略可以看到前方
站著一位老人，而老人的身旁有一座雕像，與把你吸進來的雕像相似。
LONG);
set("objects",([
__DIR__"statue":1,
]));
set("light_up",1);
set("no_transmit",1);
set("no_chome",1);
setup();
}
