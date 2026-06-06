// Room: /u/d/devils/school4.c

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
你站在正晴武館的東北隅,你眼前擺滿了武器架,武器架上刀槍劍戟
樣樣齊全，在眾多架子之中以放棍的武器架雕飾最為華麗，棍架上還掛
著一個牌子(sign)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"school7",
  "west" : __DIR__"school3",
]));

        set("outdoors", "/open/wu");
        setup();
        set("item_desc", ([
                "sign": "武器用畢，記得放回原位\n"
        ]) );
}
