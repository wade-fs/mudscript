inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 水煙閣半山亭");
  set ("long", @LONG
    這裡是一個用白石砌成的亭子﹐亭子的東面和北面都是深不見底的
懸崖﹐從這裡望出去只見一片雲霧之中突出幾座山峰﹐雲霧之中隱隱可
以看到好似水波的微光﹐使你一時之間彷彿以為這座亭子是建在一個湖
中﹐往西北望去可以看到水煙閣漂浮在雲霧之中。

LONG);

  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "westup" : "/d/cele/stair3",
  "southdown"  : "/d/cele/stair2",
]));

        set("objects", ([
                "/d/cele/npc/watcher": 1,
                "/d/cele/npc/cele_tiger": 1 ]) );

  setup();
}
