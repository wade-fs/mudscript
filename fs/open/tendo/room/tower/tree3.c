inherit ROOM;
#include <ansi.h>
void create()
{
set("short", "松林");
set("long", @LONG
漸漸地你可以感覺到前方，陽光從樹射落到地上，不在令人感到
黑暗，松樹林也漸漸稀疏了，這裡似乎已是松林的盡頭，你可以看到
前方有個小山丘。
LONG
);
set("exits",([ /* sizeof() == 2*/
"down" : __DIR__"tree2.c",
"north" : __DIR__"tomb.c",
]));
set("outdoors",1);
setup();
}

