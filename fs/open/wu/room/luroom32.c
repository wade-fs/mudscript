// Room: /open/wu/room/luroom32.c
// 瀧山內院走道
inherit ROOM;
void create ()
{
  set ("short", "內院");
	set( "build", 12 );
  set ("long", @LONG
這裡是瀧山武館內的後院,一眼望去看到有許多的廂房,後院
內種植許多的花草樹木,井然有序,西邊是通往瀧山派的禁地
北邊是通往廂房,南邊是通往瀧山派的書房。
LONG);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luroom31",
  "south" : __DIR__"luroom33",
  "west" : __DIR__"luroom29",
]));
  setup();
}
