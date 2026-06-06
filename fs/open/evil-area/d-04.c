inherit ROOM;

void create()
{
        set("short","屍骨道");
        set("long",@LONG
腳下傳來陣陣的屍臭味，這裡是一個由屍骨所堆積而成的道路，
你踏下的每一步，都會將腳下的屍骨給踩的粉碎，對於生活於人界的
你，感覺上十分的難受，在你的北邊，你可以清楚的看到一座呈現凹
字型的森林，而在你的西南方，似乎有一座湖泊，往東或南走，則步
入沙漠內。
LONG);
        set("exits",([
"north":__DIR__"d-05",
"south":__DIR__"d-06",
"west":__DIR__"d-02",
"east":__DIR__"ea-01",
]));
        set("objects",([
__DIR__"npc/die-worm":5,
]));
        set("no_transmit",1);
        set("evil-area",1);
        setup();
}
