// Room: /open/gsword/room/su5.c

inherit ROOM;

void create()
{
	set("short", "青石小徑");
	set("long", @LONG
走在青石小徑上,這裡已不是蜀中鬧區,高大的建築漸漸減少,取代
的是一般平房,人潮,也漸漸的消失了.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"su6",
  "east" : __DIR__"su1",
]));

/*	由於砍掉 beggar.c 所以乾脆這兒也關掉
        set("objects", ([
        "/open/gsword/mob/beggar" : 1,
        ]) );
*/
        set("outdoors","/open/gsword");
	setup();
}
