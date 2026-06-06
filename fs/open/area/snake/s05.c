 inherit ROOM;

void create ()
{
        set("short","蛇穴");
        set("long",@LONG
一個長筒狀的洞穴，洞穴週遭的土壤，圓滑的彷彿切割過的地形
一般，筆直而深遂的通道，令人不禁猜想，這一切並非自然天成的，
冥冥之中，彷彿有一雙看不見的幕後黑手創造了這一個不知為何的洞
穴。
LONG);
        set("objects",([
__DIR__"npc/snake01":1,
__DIR__"npc/snake03":1,
]));
        set("exits",([
"north":__DIR__"s06",
"south":__DIR__"s04",
]));

        setup();
}
