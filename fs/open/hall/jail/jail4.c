// Room: /open/hall/jail/jail4.c

inherit ROOM;

void create()
{

        set("short", "監    牢");
        set("long", @LONG
一個充滿惡臭及汙穢的地方，在牆角的石床上散亂灑著幾束稻草!!
地板上由於太過潮濕，顯的一片泥濘不堪，繼而冒出陣陣的劇毒沼氣!!
牆上斑斕的血跡，使人心裡升起了一股不祥預兆，似乎正強烈的暗示著
死亡的訊息!!
LONG);

        set("exits", ([ ]));
        set("no_clean_up", 0);

        setup();

        replace_program(ROOM);

}

