inherit ROOM;

void create()
{
        set("short","屍骨道");
        set("long",@LONG
你踏行在屍骨遍地的地方, 每行走一步都會出現〔喀啦、喀啦〕
的碎骨聲，天空不時的有幾隻巨獸徘徊著，發出的吼聲響徹整個大地
，地上又不時的跑著一些毛隆隆的小動物，十分的詭異，往南望去，
有一座呈現凹字型的湖泊，西北方則是一個閃耀著金色光芒的建築物
，而在你的東北方，則有一座森林。
LONG);
        set("exits",([
"north":__DIR__"d-03",
"south":__DIR__"d-01",
"west":__DIR__"d-07",
"east":__DIR__"d-04",
]));
        set("objects",([
__DIR__"npc/die-worm":5,
]));
        set("no_transmit",1);
        set("evil-area",1);
        setup();
}

