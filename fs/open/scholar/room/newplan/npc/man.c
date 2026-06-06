//man.c 提示八卦陣走法的npc

inherit NPC;

void create()
{
        set_name("受重傷的人", ({ "man" }) );
        set("race","人類");
        set("kee",1);
        set("age", 3);
        set("long", "\n你看他滿身鮮血, 口中喃喃自語, 不知道有什麼事情發生在他身上(ask 事情)。\n");
        setup();
}
void init()
{
add_action("do_ask","ask");
}
int do_ask(string str)
{
  object me=this_player();
  if(str=="man about 事情")
  write("你趕緊扶著面前的人, 問他發生了什麼事!!\n");
  call_out("ans1",5,me);
  return 1;
}
int ans1()
{
  object me=this_player();
  write("重傷的人說 : 你..你..你要..小心..過..這個八卦陣\n");
  call_out("ans2",5,me);
}
int ans2()
{
  object me=this_player();
   write("重傷的人說 : 因..為這個八卦..陣裡面有..八個..\n");
  call_out("ans3",5,me);
}
int ans3()
{
  object me=this_player();
  write("重傷的人說 : 諸葛家的人在...守護著...\n");
  call_out("ans4",5,me);
}
int ans4()
{
  object me=this_player();
  write("重傷的人說 : 要過..不是一件..容易的事呀...\n");
  call_out("ans5",5,me);
}
int ans5()
{
  object me=this_player();
  write("重傷的人說 : 不過...我終於把走法記下來了...\n");
  call_out("ans6",5,me);
}
int ans6()
{
  object me=this_player();
  write("重傷的人說 : 八卦..有八個方位...看似圓形\n");
  call_out("ans7_1",5,me);
}
int ans7_1()
{
  object me=this_player();
write("重傷的人說:方向..分別以...玄, 元, 練, 支四象代表東, 西, 南, 北..\n");
  call_out("ans7",5,me);
}
int ans7()
{
  object me=this_player();
write("重傷的人說 : 其實只要以...順時針方向去走\n");
  call_out("ans8",5,me);
}
int ans8()
{
  object me=this_player();
  write("重傷的人說 : 依照八卦的卦位的排列方式...\n");
  call_out("ans9",5,me);
}
int ans9()
{
  object me=this_player();
  write("重傷的人說 : 就可以..走到了...\n");
  call_out("ans10",5,me);
}
int ans10()
{
  object me=this_player();
 write("重傷的人說 : 不過記得...一進入八卦陣...你是在正北方的乾位...\n");
  call_out("ans11",5,me);
}
int ans11()
{
  object ob=this_object();
  write("重傷的人說 : 加油了呀...\n
\n說完後, 重傷的人就昏了過去..\n");
ob->die();
}
