// Room: /u/s/sueplan/newplan/area/qroom2
inherit ROOM;

void create ()
{
  set ("short", "八卦陣");
  set ("long", @LONG
                    ■■    ■■

                        ■■■■■■

                        ■■    ■■

                        坎（水）

知悉太極生兩儀﹐兩儀生四象﹐四象生八卦﹐八八六十四化﹐
此乃中國易經之妙所在﹐諸葛孔明以此而立八卦陣﹐陣內變
化萬千﹐易使人迷失於不自覺間。
你面前捲起不少的風沙, 請選出(move)你要走的方向
方向有-玄, 元, 練, 支, 練玄, 練元, 支玄, 支元。
LONG);

  set("no_auc", 1);
  set("no_transmit", 1);

  setup();
}
void init()
{
add_action("do_move","move");
}
int do_move(string str)
{
  object me=this_player();
  if(str=="玄")
  {
    me->move(__DIR__"qt2.c");
    return 1;
  }
  if(str=="元")
  {
    me->move(__DIR__"qt3.c");
    return 1;
  }
  if(str=="練")
  {
    me->move(__DIR__"qt4.c");
    return 1;
  }
  if(str=="支")
  {
    me->move(__DIR__"qt5.c");
    return 1;
  }
  if(str=="練玄")
  {
    me->move(__DIR__"qt6.c");
    return 1;
  }
  if(str=="練元")
  {
    me->move(__DIR__"gr-3.c");
    return 1;
  }
  if(str=="支玄")
  {
    me->move(__DIR__"qt7.c");
    return 1;
  }
  if(str=="支元")
  {
    me->move(__DIR__"qt8.c");
    return 1;
  }
}
