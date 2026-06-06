// Room: /open/gsword/room/lake2.c

inherit ROOM;

void create()
{
	set("short", "昆明湖東");
	set("long", @LONG
一陣和風吹佛而過,悉悉酥酥的穿過湖邊的花樹,花雨與落葉
輕飄而下,落在你的髮襟與衣領,你輕輕彈去沾在你身上的花與葉
,望著這花葉中的昆明湖,忘卻那塵世中的爭戰與煩憂....
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"su7",
  "southwest" : __DIR__"lake3.c",
  "northwest" : __DIR__"lake1.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/butterfly" : 1,
]));
        set("outdoors","/open/gsword");

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

	setup();
}
