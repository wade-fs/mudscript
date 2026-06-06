inherit "/std/room/shop";

void create ()
{
        set("short","路邊攤");
	set("long", @LONG
一個小型的攤販擺至於一旁，不過，對於這些物品，你似乎都不
太感興趣...
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west" : __DIR__"a-12",
]));
setup();
}
