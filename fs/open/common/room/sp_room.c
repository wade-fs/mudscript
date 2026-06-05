// Room: /u/c/chan/room/sp_room.c
inherit ROOM;

void create ()
{
  set ("short", "歷代狂想巫師紀念榜");
  set ("long", @LONG
狂想空間(Fantasy Space)自成立來有過很多的巫師(wizard)來這裏發展，
我在這裏很感謝他們協助，他們這裏裏花費了很多心思使這裏更好!!所以為了
表達對他們的敬意!!將他們的ID及姓名,列在下面!!!
1.Wade (創站大神)  2.Fund      3.Lum       4.Konn
5.Urd              6.Weiwei    7.Airke     8.Rence
9.bigcat          10.ccat     11.Assassin 12.Kael
13.Arthur         14.babe     15.Santo    16.xboy
17.houng          18.hide     19.cccc     20.daniel
21.Roger *        22.Acelan * 23.Wataru * 24.Leei *
25.ookami         26.Swy *    27.Superobs * 28.poloer *
29.kabn *         30.Cgy *    31.elon    32.mineral
33.een            34.floe     35.hades     36.jcder
37.jesse          38.mad      39.server  40.spirits
41.shorst         42.wasami   43.onion

ps:*代表目前還在.....
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" :__DIR__"inn",
]));
  set("light_up", 1);

  setup();
}
