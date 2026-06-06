//written by acelan...../u/a/acelan/room/wood23.c

inherit ROOM;

void create()
{
        set("short", "神祕的地道");
        set("long", @LONG
走在昏暗的地道之中, 使你不時的想要回頭查看是否有奇怪的影
子, 一股莫名的危機感是你提高了警戒心, 你仔細的檢查兩旁的牆壁
不過並沒有任何的發現。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "east" : "/open/killer/mon/room/wood24.c",
       "south" : "/open/killer/mon/room/wood16.c",
   ]));
        set("no_clean_up", 0);

        setup();
        }
