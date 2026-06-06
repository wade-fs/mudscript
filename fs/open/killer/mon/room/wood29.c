//written by acelan...../u/a/acelan/room/wood29.c

inherit ROOM;

void create()
{
        set("short", "樹林上的密道");
        set("long", @LONG
在樹梢上有一隻老老的肥貓, 看起來頗為靈巧的正在抓補麻雀,
在樹的另一端有幾支流星錐及千古恨, 看來這裡似乎有殺手與人打鬥
過的樣子, 不知是追殺還是埋伏在這裡暗殺。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : "/open/killer/mon/room/wood22.c",
       "west" : "/open/killer/mon/room/wood28.c",
   ]));

        set("no_clean_up", 0);

        setup();
}
