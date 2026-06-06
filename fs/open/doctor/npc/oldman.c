//增加解銀針後三失敗時的代價交換 by blazakira 2010/11/23

#include <ansi.h>
inherit NPC;
string ask_help();
string ask_sorry();

void create()
{
  set_name("跛腳老頭", ({"old man","man"}));
  set("age",80);
  set("long", "一個跛腳的老頭，他的腳好像被什麼生物咬傷了似的。\n");
  set("inquiry",([
   "救命"   :  (: ask_help :),
   "後悔"   :  (: ask_sorry :),
   "懺悔"   :  (: ask_sorry :),
  ]));
  setup();
}

void init()
{
  object me=this_player();
  ::init();

  if(interactive(me) && !is_fighting())
  {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
  add_action("do_help","help");
  add_action("do_feed","feed");
  add_action("do_accept","accept");
  add_action("do_unaccept","unaccept");
}

int do_feed(string arg)
{
  object me, ob;
  me=this_player();

  if(arg == "man" && me->query_temp("get_pill")==1 && ob=present("tiger_cornu-pill",me))
  {
    destruct(ob);
    write("你將藥丸放入老頭的口裡，並餵了他一些水...\n" + NOR);
    write("老頭將藥丸「咕嚕！」一聲給吞了下肚...\n" + NOR);
    command("say ㄚ...果然是舒服多了，腳也沒那麼痛了，嗯！看來我是錯怪你了...");
    command("sorry "+me->query("id"));
    write("老頭提起筆又寫了封信，交給了你...\n" + NOR);
    command("say 這封信是我為我的魯莽向你跟華神醫他老人家道歉的，請收下...");
    write("你欣然的收下了這封信，內心感到相當的快樂！\n" + NOR);
    ob=new("/open/doctor/obj/sec-letter");
    ob->move(me);
    me->delete_temp("get_pill");
    me->set_temp("sec_letter",1);
    return 1;
  }
}

int do_accept()
{
  object me, ob;
  me=this_player();
  ob=new("/open/doctor/obj/letter");

  if(me->query_temp("sos_man")==1)
  {
    write("你收下了老頭的信...\n" + NOR);
    command("say 你給我老實點，把信給交到華神醫他老人家的手上啊！！");
    ob->move(me);
    me->delete_temp("sos_man");
    me->set_temp("sos_letter",1);
    return 1;
  }
}

int do_unaccept()
{
  object me=this_player();

  if(me->query_temp("sos_man")==1)
  {
    write("你對著老頭說：你個死老頭！我好心救你竟還如此囂張，這信你要送就自己送，我才懶得理你！\n" + NOR);
    command("say 唷呵！你這臭小子這麼兇ㄚ！你肯定會後悔的...嘿嘿！");
    me->set("quest/sosman",1);
    return 1;
  }
}

string ask_help()
{
  object me=this_player();

  if(me->query("class")=="doctor" && !me->query("quest/sosman")==1 && me->query("combat_exp")>=500000 && !me->query_temp("sos_man")==1)
  {
    write("你見到老頭的臉色瞬間大變...\n" + NOR);
    command("cow "+me->query("id"));
    call_out("do_help1",1,me);
    return "";
  }
  return 0;
}

string ask_sorry() //當華陀醫術 (godcure)=lv 100時 允許重解 並要求代價
{
  object me=this_player(),ob;
  if(me->query_skill("godcure",1) <100)
    return "哼哼～連醫術都學不好了還想救我，滾！";
  if(!me->pay_money(1000000))
    return "哼哼～你當我好欺負呀，最少也要一百兩黃金。";
  if(me->query("class")=="doctor" && me->query("quest/sosman")==1 && me->query("combat_exp")>=500000 && me->query_skill("godcure",1) ==100)
  {
    write("你老老實實對著老頭鞠躬道歉...\n發誓會繼續學習醫術並將之發揚光大。\n" + NOR);
    me->set_skill("godcure",90); //華陀醫術
    command("pat "+me->query("id"));
    write(HIY + "跛腳老頭撚了撚鬍鬚道：你果然後悔了吧，年輕人不應該太衝動的，要是以前的我遇到像你\n" + NOR,me);
    write(HIY + "　　　　　　　　　　　這樣的傢伙時，哪可能像現在這樣跟你搭話。\n" + NOR,me);
    write(HIY + "　　　　　　　　　　　老實點，把這封告狀信交到華神醫他老人家的手上啊！\n" + NOR,me);
    ob=new("/open/doctor/obj/letter");
    write("你收下了老頭的信...\n" + NOR);
    ob->move(me);
    me->delete_temp("sos_man");
    me->set_temp("sos_letter",1);
    return "";
  }
  return 0;
}

int do_help1(object me)
{
  write(HIY + "跛腳老頭怒道：你是個醫生ㄟ！你居然問我如何救命？\n" + NOR,me);
  call_out("do_help2",2,me);
}

int do_help2(object me)
{
  write(HIY + "跛腳老頭怒道：我看你實在是該好好的檢討檢討了！\n" + NOR,me);
  call_out("do_help3",2,me);
}

int do_help3(object me)
{
  write(HIY + "跛腳老頭怒道：真不知道為何以華老如此神醫之尊，竟會教出你這樣的弟子！\n" + NOR,me);
  call_out("do_help4",2,me);
}

int do_help4(object me)
{
  write(HIY + "跛腳老頭怒道：你給我在這站好，我寫封信給他老人家！\n" + NOR,me);
  call_out("do_help5",2,me);
}

int do_help5(object me)
{
  write(HIY + "跛腳老頭開始寫起告狀信來...還不時以鄙視的眼神瞄你...使你感到渾身不自在...\n" + NOR,me);
  call_out("do_help6",7,me);
}

int do_help6(object me)
{
  write(HIY + "跛腳老頭拿著信對你說道：吶！你給我收好這封信...(accept/unaccept)\n" + NOR,me);
  me->set_temp("sos_man",1);
  return 1;
}

void greeting(object me)
{
  if(me->query("class")=="doctor"
    && me->query("quest/sosman")!=1
    && me->query_temp("sos_man")!=1
    && me->query("combat_exp")>=500000)
  {
    command("sos "+me->query("id"));
    command("say 你是一位醫生吧？求求你幫幫我！救命ㄚ！");
  }
  else if(me->query("class")=="doctor"
    && me->query("quest/sosman")==1)
  {
    command("say 口亨口亨！後悔了吧～後悔了吧～");
    command("say 早就跟你說你會後悔你還不相信，既然後悔了就趕緊來跟我懺悔吧。");
  }
  else
  {
    command("sos");
  }
}
