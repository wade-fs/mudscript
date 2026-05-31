inherit BULLETIN_BOARD;
void create()
{
  set_name("魔刀千字牆", ({"board"}));
  set("location", "/open/gblade/room/secret");
  set("board_id", "mou_b");
  set("long","
上面龍飛鳳舞的寫著一些東西，都是莫無愁多年練功\所發展的武功\招式
心得，旁邊還夾雜一些奇怪的文字，看也看不懂。\n" );
  setup();
  set("capacity", 35);
  set("master",({"swy"}));
}
