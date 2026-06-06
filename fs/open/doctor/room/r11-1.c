inherit ROOM;
void create()
{
        set("short", "曬藥臺");
        set("long", @LONG
站在這裡，景色豁然開朗，可以遠挑遠處的景物，偶爾還有柔柔
的清風吹拂過你的臉，這種地方用來曬藥太可惜了，你心裡面想著，
要是拿來收門票那不就賺死了。

LONG
        );
        set("can_search",1);
        set("outdoors",1);
        set("exits", ([ /* sizeof() == 1 */
       "down" : __DIR__"r11",
]));
        set("no_clean_up", 0);

        setup();
        }


