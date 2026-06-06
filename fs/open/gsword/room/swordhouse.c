// Room: /open/gsword/room/swordhouse
inherit ROOM;

void create ()
{
  set ("short", "五嶽劍盟");
	set( "build", 14 );
  set ("long", @LONG
這裡是天下劍客同盟在蜀中的聯絡處,灰斜的屋瓦,參白的牆
壁,雖不華麗,卻顯得莊重.你見到許多劍客進出這裡.左首有個
告示牌(board),似乎在說明如何成為劍士的一員.



LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/gsword/room/su10",
]));

  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "招牌上寫著 :
你想成為劍士公會的一員嗎?
你想做個人人欽佩的劍俠嗎?
很簡單 ,只要打個(join)即可加入我們劍士公會
以後就能在大陸上各大劍派拜師學藝了.
",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/swordsman/master-1" :1,
]));

  set("light_up", 1);

  setup();
}
