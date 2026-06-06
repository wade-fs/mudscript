inherit ROOM;
void create()
{
   set("short","密室");
   set("long",@LONG
這是一間極為隱密的房間,每當段家的弟子修行遇到瓶頸,
便會來這裡閉關,有時一來就是好幾年,這裡的陳設極為簡
陋,但是冬暖夏涼,非常適合在這裡練功.

LONG);

   set("exits", ([ /* sizeof() == ? */
   "leave" : "/open/ping/room/p9.c",
   ]));

   set("valid_startroom", 1);
   set("no_clean_up",1);
   set("light_up",10);
        set("no_fight",1);
   setup();
}
