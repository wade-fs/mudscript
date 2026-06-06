// Room: /open/wu/room/luroom4.c
// 瀧山武館的練武場
inherit ROOM;
void create()
{
        set("short", "練武場");
        set("long", @LONG
你站在瀧山派練武場的一角,你眼前擺滿了許多的木頭人,木頭人身上拳
痕磊磊,指痕處處,想必是武館弟子用來練拳的地方,你看到教頭正在教導
武館弟子如何發勁、拆招的方式。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"luroom3",
        "east" : __DIR__"luroom7",
]));
        set("objects", ([ /* sizeof() == 1 */
        "/open/wu/npc/c_trainee" : 3,
        "/open/wu/npc/c_trainer" : 1,
     ]));
        setup();
}
