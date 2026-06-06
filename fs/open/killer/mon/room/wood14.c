//written by acelan...../u/a/acelan/room/wood14.c

inherit ROOM;

void create()
{
        set("short", "後山的森林");
        set("long", @LONG
你來到了森林的邊緣, 一棵大樹擋住了你的去路, 樹的上面傳來
陣陣的腳步聲, 似乎另有通道, 你用盡了各種方法卻仍然無法上去,
你想, 也許應該找另外的入口。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : "/open/killer/mon/room/wood9.c",
        "north" : "/open/killer/memory/hr1.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc3.c":2,
   ]));
   set("no_clean_up", 0);

   setup();
}
