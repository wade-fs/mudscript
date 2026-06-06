inherit ROOM;

void create()
{
        set("short", "藥圃");
        set("long", @LONG
看過來看過去，抬抬頭再看看地，這裡是一片水窪地，連個藥材的蹤影
都沒有，嗯嗯嗯～這裡有種東東嗎？？

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r10",
  "north" : __DIR__"r8",
]));
        set("can_search",1);
        set("no_clean_up", 0);
        set("outdoors", 1);

        setup();
        }


