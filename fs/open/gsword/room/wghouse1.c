// Room: /open/gsword/room/wghouse1.c
inherit ROOM;

void create()
{
  set ("short", "藏經閣");
  set ("long", @LONG
這是仙劍派用以典藏武學秘笈之處，據說只有經過掌門人的許可，
才可到此翻閱武功秘笈，因此地上積了一層厚厚的灰塵，連秘笈由於
年代久遠，也是殘破不全。
LONG);

  set("light_up", 1 );

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wghouse",
]) );

  setup();
}
