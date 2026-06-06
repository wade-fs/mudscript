inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "別有洞天");
        set ("long", @LONG
想不到在這樣的山洞之中還有這樣的一個地方，裏面光線充足，
長滿了各式奇異的花花草草，還有各種珍奇的藥草，另外有一棵水果
樹在這洞天的一角，樹上還長了兩顆碩大的果實，令你想一嚐牠鮮美
的滋味，但是你卻一直聞到一股更奇特的味道從另一方傳了過來。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "out"      : __DIR__"mon29",
        "east"     : __DIR__"mon31",

]));
        setup();
}

