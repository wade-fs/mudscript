 inherit ROOM;

void create ()
{
        set("short","蛇穴盡頭");
        set("long",@LONG
一個長筒狀的洞穴，洞穴週遭的土壤，圓滑的彷彿切割過的地形
一般，筆直而深遂的通道，令人不禁猜想，這一切並非自然天成的，
冥冥之中，彷彿有一雙看不見的幕後黑手創造了這一個不知為何的洞
穴。
洞口的盡頭彷彿一片光滑無瑕疵的鏡子，橢圓形的直立在眼前，四周
除多一點蛇以外，必沒有其他特別的地方．
LONG);
        set("objects",([
__DIR__"npc/snake01":3,
__DIR__"npc/snake02":3,
__DIR__"npc/snake03":3,
]));
        set("exits",([
"south":__DIR__"s09",
]));

        setup();
}
