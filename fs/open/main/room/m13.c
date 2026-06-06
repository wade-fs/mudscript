// Room: /open/main/room/M13.c

inherit ROOM;

void create()
{
        set("short", "崑崙山");
        set("long", @LONG
        抬頭望去，這條長廊附隨著山勢蜿蜒而上，直入雲
        霧中，令人無法想像它到底有多長多高，有如神龍
        般的見首不見尾，無法捉摸。
        

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"M12",
  "east" : __DIR__"M14",
]));
        set("outdoors", "1");

        setup();
}
