inherit ROOM;

void create()
{
        set("short","屍骨道");
        set("long",@LONG
屍骨的傳來陣陣的惡臭位，腳底下踩著骨頭前進，你部自主的感
覺到罪惡，卻也有一股前所未有的新鮮感，往北望去，有一座巨大的
沙丘呈現凹字型的包圍著出入口，往西、南走則步入沙漠。
LONG);
        set("exits",([
"north":__DIR__"d-14",
"south":__DIR__"d-15",
"east":__DIR__"d-10",
]));
        set("objects",([
__DIR__"npc/die-worm":5,
]));
        set("no_transmit",1);
        set("evil-area",1);
        setup();
}
