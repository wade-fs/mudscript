//將save_die 統一名稱為聖手回春術 而非聖手回春術 by blazakira 2011/3/19

#include <ansi.h>
inherit NPC;

string ask_fon();
string ask_but();
string ask_baby();

void create()
{
  set_name("華雲峰", ({"hwa yun fon","hwa","fon","yun"}) );
  set("long", "
他就是目前世上唯一身負「不傳之技」的銀針門前輩，
聽說當年其灸功\堪稱天下一絕！\n");
  set("gender", "男性");
  set("title", HIC"面壁十年"NOR);
  set("age", 65);
  set("inquiry",([
    "不傳之技" : (: ask_fon :),
    "條件"     : (: ask_but :),
    "宇內五禽" : (: ask_baby :),
  ]));
  set("attitude", "peaceful");
  setup();
}

string ask_fon()
{
  object me=this_player();

  if(me->query("doctor/get_mark") == 1 && !me->query("doctor/save_die") 
    && me->query("class")=="doctor")
  {
    if(!me->query("doctor/ask_fon"))
      {command("shake "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else if(me->query("doctor/ask_fon") == 1)
      {command("think "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else if(me->query("doctor/ask_fon") == 2)
      {command("hmm "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else if(me->query("doctor/ask_fon") == 3)
      {command("arc "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else if(me->query("doctor/ask_fon") == 4)
      {command("stare "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else if(me->query("doctor/ask_fon") == 5)
      {command("dunno "+me->query("id")); me->add("doctor/ask_fon",1); return "";}
    else
    {
      command("tsk "+me->query("id"));
      command("say 沒想到你竟然這麼有耐性！");
      command("say 好吧！既然你我如此有緣分...");
      command("say 我就把『聖手回春術』傳授給你！");
      command("say 但在這之前有個條件...");
      command("grin "+me->query("id"));
      me->delete("doctor/get_mark");
      me->set("doctor/ask_fon",1);
      return "";
    }
  }
}

string ask_but()
{
  object me=this_player();

  if(me->query("doctor/ask_fon") == 1)
  {
    command("wa "+me->query("id"));
    command("say 好極了！你跟你的憋腳師父果然不同...");
    command("cac "+me->query("id"));
    command("say 我這個人平常除了練功\就只有蒐集寶物這個嗜好...");
    command("say 如今「宇內五禽」我已得其三...");
    command("say 不知你能否幫我找到其餘的兩樣咧？");
    me->delete("doctor/ask_fon");
    me->set("doctor/ask_but",1);
    return "";
  }
}

string ask_baby()
{
  object me=this_player();

  if(me->query("doctor/ask_but") == 1)
  {
    command("say 宇內五禽是指「魔龍鱗」、「火鳳羽」、「真龜血晶」、「麒麟聖爪」以及「天山鷹翅」...");
    command("say 我現在只差兩樣尚未蒐集到手...");
    command("say 其一便是魔界守護者炎龍的鱗片...世稱「魔龍鱗」");
    command("say 而其二則是瀧山之鎮派聖獸火鳳的羽毛...世稱「火鳳羽」");
    command("say 魔龍鱗之取得不難，但若欲向任正晴索得火鳳羽，恐怕就不是件易事了...");
    command("say 不過...我聽說任正晴的大兒子相當貪杯，你不妨就由此下手...");
    command("say 我言盡於此...接下來就看你自己的了...");
    command("addoil "+me->query("id"));
    me->delete("doctor/ask_but");
    me->set("doctor/ask_baby",1);
    return "";
  }
}

int accept_object(object me, object ob)
{
  string obj;
  int force = (int)me->query_skill("force",1);
  obj = ob->query("name");

  if(me->query("doctor/ask_baby") == 1 && !me->query("doctor/save_die"))
  {
    if(obj == HIY"魔龍鱗"NOR)
    {
      command("tsk");
      command("say 好極了！原來這就是真正的"+ obj +"！");
      me->set("doctor/give_baby1", 1);
      destruct(ob);
      if(!me->query("doctor/give_baby2") == 1)
      {
        command("say 咦...還有一個火鳳羽咧？");
        return 1;
      }
      command("spank "+me->query("id"));
      command("say 你的表現真是令我刮目相看...");
      command("say 想不到...都十年了...終於讓我等到你了...");
      command("say 這兩樣寶物...哈哈！鬼才蒐集....");
      command("say 嗯...現在我便信守諾言，傳授你『聖手回春術』！");
      message_vision("只見華雲峰雙掌貼於你的背心，將其體內的「天靈罡\氣」緩緩的輸入$N的體內...\n", me, ob);
      message_vision("$N的背心感到一股暖流慢慢流入，功\力似乎有所大進！\n", me);
      me->set("doctor/save_die", 1);
      me->do_command("sk");
      me->set_skill("force",force+5);
      message_vision(HIC"$N的「基本內功\」進步了﹗\n"NOR+
                     HIC"$N的「基本內功\」進步了﹗\n"NOR+
                     HIC"$N的「基本內功\」進步了﹗\n"NOR+
                     HIC"$N的「基本內功\」進步了﹗\n"NOR+
                     HIC"$N的「基本內功\」進步了﹗\n"NOR, me);
      me->delete("doctor/ask_baby");
      me->delete("doctor/give_baby1");
      me->delete("doctor/give_baby2");
      me->delete("doctor/get_mark");
      me->delete("doctor/start_quest");
      me->delete("doctor/get_key");
      me->delete("doctor/get_fea");
      log_file("quest_savedie", sprintf("%s(%s) 解開聖手回春術 on %s(獎勵前的force_lv為%d，獎勵後的force_lv為%d)\n"
        ,me->query("name"),me->query("id"), ctime(time()), force, me->query_skill("force",1)));
      call_out("fon_die",2,me);
      return 1;
    }
    else if(obj == HIR"火鳳羽"NOR)
    {
      command("tsk");
      command("say 好極了！原來這就是真正的"+ obj +"！");
      me->set("doctor/give_baby2", 1);
      destruct(ob);
      if( !me->query("doctor/give_baby1") == 1)
      {
        command("say 咦...還有一個魔龍鱗咧？");
        return 1;
      }
      command("spank "+me->query("id"));
      command("say 你的表現真是令我刮目相看...");
      command("say 想不到...都十年了...終於讓我等到你了...");
      command("say 這兩樣寶物...哈哈！鬼才蒐集....");
      command("say 嗯...現在我便信守諾言，傳授你『聖手回春術』！");
      message_vision("只見華雲峰雙掌貼於你的背心，將其體內的「天靈罡\氣」緩緩的輸入$N的體內...\n", me, ob);
      message_vision("$N的背心感到一股暖流慢慢流入，功\力似乎有所大進！\n", me);
      me->set("doctor/save_die", 1);
      me->do_command("sk");
      me->set_skill("force",force+5);
      message_vision(HIC"$N的「基本內功\」進步了﹗\n"NOR+
                     HIC"$N的「基本內功\」進步了﹗\n"NOR+
                     HIC"$N的「基本內功\」進步了﹗\n"NOR+
                     HIC"$N的「基本內功\」進步了﹗\n"NOR+
                     HIC"$N的「基本內功\」進步了﹗\n"NOR, me);
      me->delete("doctor/ask_baby");
      me->delete("doctor/give_baby1");
      me->delete("doctor/give_baby2");
      me->delete("doctor/get_mark");
      me->delete("doctor/start_quest");
      me->delete("doctor/get_key");
      me->delete("doctor/get_fea");
      log_file("quest_savedie", sprintf("%s(%s) 解開聖手回春術 on %s(獎勵前的force_lv為%d，獎勵後的force_lv為%d)\n"
        ,me->query("name"),me->query("id"), ctime(time()), force, me->query_skill("force",1)));
      call_out("fon_die",2,me);
      return 1;
    }
  } else {
    command("arc "+me->query("id"));
    command("say 你給我的這是啥鬼東西？");
    ob->move(me);
    message_vision("華雲峰將"+ obj +"交還給$N...\n", me);
    return 1;
  }
}

int fon_die(object me)
{
  write(HIY"華雲峰突然急撤雙手，一時頭暈目眩，口吐鮮血...\n"NOR,me);
  call_out("fon_die2",1,me);
}

int fon_die2(object me)
{
  write(HIY"你趕緊為他把把脈，並按摩其各大脈穴...\n"NOR,me);
  call_out("fon_die3",5,me);
}

int fon_die3(object me)
{
  write(HIY"須臾...華雲峰總算是醒了過來...\n"NOR,me);
  call_out("fon_die4",2,me);
}

int fon_die4(object me)
{
  write(HIY"華雲峰上氣不接下氣的說道：使...用方...式...是..."HIG"cmd"HIY"..."HIG"save_die"HIY"...\n"NOR,me);
  write(HIY"華雲峰吃力的說道：如...如今...我...已將...此技傳...傳...受予你.....望你好好善用...造福世人...\n"NOR,me);
  call_out("fon_die5",2,me);
}

int fon_die5(object me)
{
  write(HIY"說完此話，華雲峰便因氣力用盡而撒手人寰，與世長辭了...\n"NOR,me);
  tell_object(users(),HIW"
華陀笑道："HIY"嗚呼哀哉—\n
          "HIY"逝者已矣，來者猶可追。\n
          "HIG""+this_player()->name()+""HIY"吾徒！\n
          唯一慶幸的是咱"HIW"銀針門"HIY"的"HIR"不傳之技"HIY"終於又有傳人了！！\n\n"NOR);
  this_object()->die();
  return 1;
}
