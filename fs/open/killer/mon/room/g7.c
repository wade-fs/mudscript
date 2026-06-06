//written by wataru...../open/killer/mon/room/g7.c
inherit ROOM;

void create()
{
        set("short", "綠雲組內部");
        set("long", @LONG
	你逐漸地懷疑你是否在綠雲組之內了，因為整個綠雲組，
	根本就與這一棵樹合為一體，要不是有綠雲組的人員在此。
	你真的很難以想像你是身在神秘的綠雲組中，
	看來傳說中，綠雲組是天才機關手諸岡渡所做，這一點是錯不了了。

LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "east" : __DIR__"g1.c",
       "south" : __DIR__"g8.c",
   ]));
        setup();
}
