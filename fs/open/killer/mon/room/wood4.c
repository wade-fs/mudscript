//written by acelan...../u/a/acelan/room/wood4.c

inherit ROOM;

void create()
{
        set("short", "後山森林");
        set("long", @LONG
你似乎感覺到有人影在樹上晃動, 但卻又看不到任何東西, 你覺
得這可能是自己的錯覺, 一陣陣強風吹來, 樹影晃動, 落葉紛紛, 更
加添了你心中的寒意, 你決定加快腳步, 離開這片可怕的樹林。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : "/open/killer/mon/room/wood9.c",
       "west"  : "/open/killer/mon/room/wood3.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc3.c":2,
   ]));
   set("no_clean_up", 0);

   setup();
}
