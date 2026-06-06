//新增皆傳之證解謎要素 by frequency 2003 Jan
//新增寰宇渾天勁解謎要素 by frequency 2003 may
//增加新手quest 尋找武林盟主的下落 by blazakira 2011/6/29
//調整拜師的順序 by blazakira 2011/8/19

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

string do_tengin();
string magic_manor1();
string magic_manor2();
string magic_manor3();
string fist_book();
string magic_palace();
string adv_prayer();
string ask_universe();
string ask_superforce();

void create()
{
  set_name("林宏昇",({"pope lin","pope","lin"}));
  set("long",@LONG

        沒有人知道他的來歷，也沒人知道他的武功有多深；是一個神秘莫
        測的人物，在三年前因風雲際會，使他創立了〔聖火教〕，也不知
        他是用何方法建立這個龐大的組織，也因為如此，他被江湖上的人
        稱為〔武林神話〕。

LONG);
  set("gender","男性");
  set("clan_kill",1);
  set("class","prayer");
  set("nickname","武林神話");
  set("title","聖火教皇～～");
  set("combat_exp",7000000);
  set("attitude","heroism");
  set("score",1000000);
  set("age",75);
  set("max_kee",15000);
  set("str",50);
  set("cor",50);
  set("cps",45);
  set("int",42);
  set("marks/tengin",1);
  set("force",50000);
  set("max_force",50000);
  set("force_factor",40);
  set("max_gin",10000);
  set("max_sen",10000);
  set_skill("cure",120);
  set_skill("superforce",250);
  set_skill("dodge",120);
  set_skill("force",150);
  set_skill("move",120);
  set_skill("literate",120);
  set_skill("parry",120);
  set_skill("array",130);
  set_skill("fire-array",130);
  set_skill("unarmed",120);
  set_skill("canon",150);
  set_skill("literate",120);
  set_skill("shift-steps",150);
  set_skill("universe",140);
  map_skill("force","superforce");
  map_skill("dodge","shift-steps");
  map_skill("move","shift-steps");
  map_skill("parry","universe");
  map_skill("array","fire-array");
  map_skill("unarmed","universe");
  set("functions/blood/level",200);
  set("functions/tengin/level",100);
  set("functions/bluesea/level",120);
  set("env/天驚地動",5);
  set("env/superforce","blood");
  set("env/連擊","YES");
  set("inquiry",([
    "天驚地動"       :       (: do_tengin :),
    "聚靈引"         :       (: magic_manor1 :),
    "聚靈山莊"       :       (: magic_manor2 :),
    "三件事"         :       (: magic_manor3 :),
    "無雙寺"         :       (: fist_book :),
    "魔宮"           :       (: magic_palace :),
    "最終絕學"       :       (: adv_prayer :),
    "河圖系"         :       (: ask_universe :),
    "洛書系"         :       (: ask_superforce :),
    "浪清心"         :       "清心是我所第一個收的弟子，原為教皇繼承人，他的武學天份之高，遠超過本派歷代先人。",
    "太陰虛幻神鑑"   :       "是夜夢雙妖所使用的魔法，其中的水月神鏡非常厲害，我看你要是遇到了大概會仆在當場。",
    "夜夢雙妖"       :       "雖然夜夢雙妖已被清心所殺，但聽說他們的傳人最近在魔界相當囂張。",
    "先天乾坤功\正卷":       "傳說正卷上記載了超越天驚地動的無敵神技，可惜現在下落不明。",
    "遺落的渾天水晶" :       "嗯，本教目前僅餘六枚水晶，若集齊其他四枚，應能將渾天寶鑑推至最終境界。",
    "玄清子"         :       "聽說他的後人陸清風老道，對洛書河圖也蠻有一番心得的。",
    "月無垠"         :       "我懷疑她當時將其餘渾天水晶暗中藏起來了，但是月半彎那婊子打死都不承認。",
    "武林盟主"       :       "我很忙！最近常有人來挑戰我，有事你問總管去！",
  ]));
  set("chat_chance",1);
  set("chat_msg",({
                CYN"教皇吟道﹕「慾海浮沈名利爭，電光火石此步生；\n
                        紅塵世事揮不盡，渡世不笑是痴人。」\n"NOR,
                CYN"教皇笑道﹕「孤卒浴血鬥志高，賢仕善謀腦中計，\n
                        一炮轟開險關道，單車護帥越天河。」\n"NOR,
                CYN"教皇嘆道﹕「萬里雄兵氣如虹，千秋定論難爭峰；\n
                        昊日顯照星光掩，百川匯宗誰與共。」\n"NOR,
                CYN"教皇樂道﹕「百年世事空華裡，一片身心水月間；\n
                        獨許\萬山深密處，晝長趺坐掩松關。」\n"NOR,
                CYN"教皇悲道﹕「命裏有時終須有，凡事不可強求；\n
                        時至運就到，蒼天不會辜負苦心人啊。」\n"NOR,
                CYN"教皇念道﹕「夜涼撫琴千山月，路遙迷人千種花；\n
                        棋罷不知人換世，酒欄無奈客恩家。」\n"NOR,
                CYN"教皇沈吟道﹕「隱居幽靈古洞天，苦學秘笈無限年；\n
                        誰若超越一線界，休怪氣功\穿腦田。」\n"NOR,
                CYN"教皇說道﹕「靜月禁地是仙境，休望侵犯取月靈；\n
                        若要逞強不聽勸，閃電霹靂奪性命。」\n"NOR,
  }) );
  set("chat_chance_combat",50);
  set("chat_msg_combat",({
    (: perform_action,"force.blood3" :),
    (: perform_action,"force.bluesea3" :),
  }));
  setup();

  add_money("cash",2);
  carry_object("/open/prayer/obj/boris-boots")->wear();
  carry_object("/open/prayer/obj/boris-cloth")->wear();
  carry_object("/open/prayer/obj/boris-hat")->wear();
  carry_object("/open/prayer/obj/boris-hands")->wear();
  carry_object("/open/prayer/obj/kylin-belt")->wear();
  carry_object("/open/prayer/obj/dragon-icer")->wield();
  create_family("聖火教",1,"教皇");
  carry_object("open/prayer/obj/lin-head");
}

void init()
{
  add_action("do_join","join");
  add_action("do_select","select");
  add_action("do_verify","verify");
  ::init();
}

int accept_fight(object who)
{
  return notify_fail("教皇冷冷的道 : 去.去..去...少來煩我。\n");
}

int do_verify(string arg)
{
  object me,ob,ob1;
  me=this_player();
  ob=new("open/prayer/obj/woodboard");
  ob1=new("open/prayer/obj/ironboard");
  if( arg!="board")
  {
    write("你要申請什麼？\n");
    return 1;
   }
  if(me->query("family/family_name")!="聖火教")
  {
    write("只有聖火教徒才會有信物。\n");
    return 1;
  }

  if( present("wood board",me) || present("iron board",me) )
  {
    write("你已經申請過了。\n");
    return 1;
  }

  if ( me->query("marks/文武星君") )
  {
    write("這是聖火教幹部的專用鐵牌!!可不要掉了!!\n");
    ob1->move(me);
    return 1;
  }
  else
  {
    write("這是聖火教的信物，望你好好保存，切勿遺失了。\n");
    ob->move(me);
    return 1;
  }
}

void attempt_apprentice(object ob)
{
  if(ob->query("marks/文武星君")==1) //第四階段拜師
  {
    if(ob->query("combat_exp")<=2500000)
    {
      command("? " +ob ->query("id"));
      command("say 你不是已經是文武星君的入室弟子了嗎？");
      command("say 以你的程度還不夠資格跟我學習武學與教務的處理吧！");
      command("say 好好跟著文武星君多磨練磨練吧！");
      return 0;
    }
    else
    {
      command("look "+ob->query("id"));
      command("pat "+ob->query("id"));
      command("say 好，你果然是可造之才，從今後就由本教主親自教導！");
      ob->delete("family");
      command("recruit "+ob->query("id"));
      ob->set("title","聖火教嫡傳弟子");
      message("mud","聖火教皇～～林宏昇放聲大笑: \n
        哈哈哈哈....本教主實在太高興啦!!\n
        "+ob->name()+"今後聖火教的重擔就落在你的肩上了，\n
                        好好幹吧!!老夫不會虧侍你的!!\n",users());
      return ;
    }
  }
  else if(ob->query("marks/聖火三長老")==1) //第三階段拜師
  {
    if(ob->query("combat_exp")<=900000)
    {
      command("? " +ob ->query("id"));
      command("say 你不是已經拜過三位長老作為老師了嗎？");
      command("say 以你的程度來看，目前還不夠資格跟我學習武學與教務的處理吧！");
      command("say 好好跟著長老們再多學幾年吧！");
      return 0;
    }
    else
    {
      command("look "+ob->query("id"));
      command("pat");
      command("say 好，你果然不是泛泛之輩，你可以去找教內的文武星君作為你武學的指導！");
      ob->delete("family");
      command("say 你可以選擇武星君(warrior)或是文星君(literate)");
      ob->set_temp("allow_select",1);
    }
  }
  else if(ob->query("marks/聖火八天門")==1) //第二階段拜師
  {
    if(ob->query("combat_exp")<=200000)
    {
      command("? " +ob ->query("id"));
      command("say 你不是拜過八天門的門主了嗎？");
      command("say 以你的程度還不夠資格跟我學習武學與教務的處理吧！");
      command("say 好好跟著你自己的師父多學幾年吧！");
      return 0;
    }
    else
    {
      command("look "+ob->query("id"));
      command("pat "+ob->query("id"));
      command("say 好，你果然是可造之才，你可以去找三位長老作為你武學的指導！");
      ob->delete("family");
      command("say 你想選擇(select)哪一位長老呢？");
      command("say 傳功\長老(gonfu_elder)，執法長老(lawyer_elder)還是戒律長老(behavior_elder)？");
      ob->set_temp("allow_select",1);
    }
  }
  else { //第一階段拜師 入門
    command("hmm");
    command("say 我教務繁忙，你去找聖火八天門的門主吧！");
    command("say 你想進入(select)哪一門呢？");
    command("say 你可以選擇天機門(tangi)，天樞門(tanshu)，天權門(tanchun)");
    command("say 你可以選擇天璇門(tanshun)，玉衡門(uhen)，開陽門(kiyan)");
    command("say 你可以選擇瑤光門(youkoun)，陣勢門(zhenche)");
    ob->set_temp("allow_select",1);
  }
}

int do_join()
{
  if(this_player()->query("class"))
    return notify_fail("你已經加入其他工會了。\n");
  if(this_player()->query("officer_class"))
    return notify_fail("教皇冷冷的說道：你在中原己當過官了，我聖火教不歡迎你!!\n");
  this_player()->set("class","prayer");
  message("mud","\n聖火教皇～～林宏昇 : 哈.哈..哈...\n
各位聖火教的弟子們，\n
讓我們歡迎" +this_player()->name()+"加入我聖火教!!\n\n",users());
  return 1;
}

int do_select(string str)
{
  object who;
  who=this_player();
  if(!who->query_temp("allow_select"))
  {
    command("say 我又沒答應讓你挑。");
    return 1;
  }
  else if(who->query_temp("have_say")==1)
  {
    message_vision(sprintf(HIC"$N說道﹕"+str+"\n"NOR),who);
    command("say 你不是挑過了？");
    return 1;
  }
  else if(str=="天機門" ||  str == "tangi")
  {
    message_vision(HIC"$N說道﹕天機門。\n"NOR,who);
    who->set_temp("allow_1",1);
    command("smile");
    command("say 嗯，你就去加入天機門吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "天樞門" || str == "tanshu")
  {
    message_vision(HIC"$N說道﹕天樞門。\n"NOR,who);
    who->set_temp("allow_2",1);
    command("smile");
    command("say 嗯，你就加入天樞門吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "天權門" || str == "tanchun")
  {
    message_vision(HIC"$N說道﹕天權門。\n"NOR,who);
    who->set_temp("allow_3",1);
    command("smile");
    command("say 嗯，你就進去天權門修練吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "天璇門" || str == "tanshun")
  {
    message_vision(HIC"$N說道﹕天璇門。\n"NOR,who);
    who->set_temp("allow_4",1);
    command("smile");
    command("say 嗯，你就到天璇門好好磨練吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "玉衡門" || str == "uhen")
  {
    message_vision(HIC"$N說道﹕玉衡門。\n"NOR,who);
    who->set_temp("allow_5",1);
    command("smile");
    command("say 嗯，你就加入玉衡門吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "開陽門" || str == "kiyan")
  {
    message_vision(HIC"$N說道﹕開陽門。\n",who);
    who->set_temp("allow_6",1);
    command("smile");
    command("say 嗯，你就前往開陽門學習吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "瑤光門" || str == "youkoun")
  {
    message_vision(HIC"$N說道﹕瑤光門。\n"NOR,who);
    if(who->query("gender") != "女性")
      command("say 你不是女性，瑤光門恐怕不會收你的！另選一個吧。");
    else
    {
      who->set_temp("allow_7",1);
      command("smile");
      command("say 嗯，你就前去瑤光門拜師學藝吧！");
      who->set_temp("have_say",1);
    }
    return 1;
  }
  else if(str == "陣勢門" || str == "zhenche")
  {
    message_vision(HIC"$N說道﹕陣勢門。\n"NOR,who);
    who->set_temp("allow_8",1);
    command("smile");
    command("say 嗯，你就前去陣勢門拜師學藝吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "傳功\長老" || str == "gonfu" || str == "gonfu_elder")
  {
    if(who->query("combat_exp") < 200000){
      command("say 你這傢伙經驗不足，去八天門多學點東西吧!!");
      return 1;
    }
    if(!who->query("marks/聖火八天門")){
      command("say 連八天門都沒去過，還想去長老那學習??你這叫痴心妄想!!");
      return 1;
    }
    message_vision(HIC"$N說道﹕傳功\長老。\n"NOR,who);
    who->set_temp("allow_9",1);
    command("smile");
    command("say 嗯，你就去傳功\長老那兒學藝吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "執法長老" || str == "lawyer" || str == "lawyer_elder")
  {
    if(who->query("combat_exp") < 200000){
      command("say 你這傢伙經驗不足，去八天門多學點東西吧!!");
      return 1;
    }
    if(!who->query("marks/聖火八天門")){
      command("say 連八天門都沒去過，還想去長老那學習??你這叫痴心妄想!!");
      return 1;
    }
    message_vision(HIC"$N說道﹕執法長老。\n"NOR,who);
    who->set_temp("allow_10",1);
    command("smile");
    command("say 嗯，你就去執法長老那兒學藝吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "戒律長老" || str == "behavior" || str == "behavior_elder")
  {
    if(who->query("combat_exp") < 200000){
      command("say 你這傢伙經驗不足，去八天門多學點東西吧!!");
      return 1;
    }
    if(!who->query("marks/聖火八天門")){
      command("say 連八天門都沒去過，還想去長老那學習??你這叫痴心妄想!!");
      return 1;
    }
    message_vision(HIC"$N說道﹕戒律長老。\n"NOR,who);
    who->set_temp("allow_11",1);
    command("smile");
    command("say 嗯，你就去戒律長老那兒學藝吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "武星君" || str == "warrior")
  {
    if(who->query("combat_exp") < 900000){
      command("say 你這傢伙經驗不足，去長老那學點東西吧!!");
      return 1;
    }
    if(!who->query("marks/聖火三長老")){
      command("say 連長老那都沒去過，還想去文武星君那學習??你這叫痴心妄想!!");
      return 1;
    }
    message_vision(HIC"$N說道﹕武星君。\n"NOR,who);
    who->set_temp("allow_12",1);
    command("smile");
    command("say 嗯，你就去武星君那兒學藝吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  else if(str == "文星君" || str == "literate")
  {
    if(who->query("combat_exp") < 900000){
      command("say 你這傢伙經驗不足，去長老那學點東西吧!!");
      return 1;
    }
    if(!who->query("marks/聖火三長老")){
      command("say 連長老那都沒去過，還想去文武星君那學習??你這叫痴心妄想!!");
      return 1;
    }
    message_vision(HIC"$N說道﹕文星君。\n"NOR,who);
    who->set_temp("allow_13",1);
    command("smile");
    command("say 嗯，你就去文星君那兒學藝吧！");
    who->set_temp("have_say",1);
    return 1;
  }
  command("say 沒這人！");
  return 1;
}

int accept_kill(object ob)
{
  int i;
  object ob1,hu_fa;
  ob1 = this_object();
  ob = this_player();
  if( !present("hu-fa",environment(ob1)) ) {
  tell_room(environment(ob1),HIW"\n突然！衝出兩位護法!!\n\n"NOR);
    for(i=0;i<2;i++)
    {
      hu_fa = new("/open/prayer/npc/hu_fa");
      hu_fa->move(environment(ob1));
      hu_fa->kill_ob(ob);
    }
  }
  write("護法縱身飛撲過來叫道：誓死保護教主!!\n");
  write("林宏昇滿臉殺氣的說道：「無知小輩!!受死吧!!!」\n");
  kill_ob(ob);
  command("perform unarmed.tengin");
  return 1;
}

void greeting()
{
  object ob = this_player();
  if(ob->query_skill("coldpoison",1) )
  {
    command("say 本教主一生光明磊落!!最痛恨學有毒術之人!!");
    kill_ob(ob);
  }
  if(ob->query("class")=="dancer")
  {
    command("say 本教主最恨那些利用美色之人!!");
    kill_ob(ob);
  }
  if(present("white-crystal",ob) && present("black-crystal",ob) && present("blue-crystal",ob) &&
     present("yellow-crystal",ob) && present("red-crystal",ob)  && present("green-crystal",ob))
  {
    command("say 你拿水晶來跟我meeting，是想研究本派的最終絕學嗎!?");
  }
}

void die()
{
  object winner=query_temp("last_damage_from");
  string name1;
  int j;
  if(!winner)
  {
    ::die();
    return ;
  }
  name1 = winner->query("name");

  // by ACKY
  if( winner->query("clan/id") && userp(winner) )
    CLAN_D->add_clanset( winner->query("clan/id"),"develop",5 );

  tell_object(users(),HIR"
   遠從西域傳來一聲怒吼!!『聖火教主』林宏昇不顧傷勢!!強運身上內力，使出了
                    "+HIW+"先天乾坤功\第七絕
                                   『"+HIC+"天"+HIG+"驚"+YEL+"地"+BLU+"動"+HIW+"』"HIW"
   一時之間，天地變色!!狂風怒嘯!!九天真氣、九地真氣，齊湧至林宏昇之体內!!!
"HIR"忽然間!!轟~~一聲巨響!!!林宏昇無法駕馭身上的九天真氣!!真氣爆体而出!!血肉模糊!!

    "+HIC+"大俠"+HIY+name1+HIC+"在旁笑道：聖火教氣數已盡!!今後是我稱霸的時代了!!哈哈!!\n\n"NOR);
  if(winner->query("family/family_name")=="仙劍派" && winner->query("killyao")==1 && winner->query("bloodsword")==1)
  {
    object ob;
    ob=new("/open/gsword/obj1/eyes.c");
    tell_object(winner,HIR"你從林宏昇的屍體上挖出了一對眼睛..\n"NOR);
    winner->set_temp("swordeyes",1);
    ob->move(winner);
  }
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj2/emperor_stone")->move(environment(winner));
        message_vision(HIM"\n從林宏昇的身上掉下了一件奇怪的東西!!\n"NOR,winner);
        write_file("/log/sky/obj2/emperor_stone",sprintf("%s(%s) 讓林宏昇掉下了皇者石於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
      {
        new("/open/sky/obj2/emperor_stone")->move(environment(winner));
        message_vision(HIM"\n從林宏昇的身上掉下了一件奇怪的東西!!\n"NOR,winner);
        write_file("/log/sky/obj2/emperor_stone",sprintf("%s(%s) 讓林宏昇掉下了皇者石於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  ::die();
}

void heart_beat()
{
  object me=this_object();
  if(random(100) < 20 && is_fighting()) {
    command("perform unarmed.tengin");
    me->delete_busy();
    me->clear_condition();
  }
  if( random(100) < 10)
  {
    if( is_fighting() && query("kee") < query("max_kee") )
    {
      message_vision(HIR"\n林宏昇出渾天心法之冰心訣，身上的傷口奇蹟式癒合了。\n"NOR,me);
      me->receive_heal("kee",1000);
      me->receive_heal("gin",200);
      me->receive_heal("sen",200);
      me->delete_busy();
      me->clear_condition();
    }
  }
  if( !me->is_fighting() && !me->query_temp("mixforce") )
  {
    command("perform force.mixforce");
  }
  if( me->is_fighting() && !me->query_temp("mixforce") )
  {
    me->delete_busy();
    command("perform force.mixforce");
  }
  ::heart_beat();
}

string do_tengin()
{
  object who=this_player();
  if(who->query("class")=="prayer")
  {
    if(who->query("combat_exp") > 3500000 )
    {
      if(who->query("marks/tengin") != 1 )
      {
        command("say 你江湖歷練已夠，且為我嫡傳弟子。");
        command("say 好吧！我傳你『天驚地動』！");
        who->set("marks/tengin",1);
        return ":)";
      } else {
        command("say 我已傳你了，好好運用吧！");
        return ":)";
      }
    } else {
      command("say 你江湖歷練不足，等 350 萬再來吧！");
      return ":)";
    }
  } else {
    command("say 我不知道！");
    return ":)";
  }
}

string magic_manor1()
{
  object me;
  me=this_player();
  if(!present("magic sign",me) && me->query("quests/can_go_magic-manor"))
  {
    command("say 這麼重要的東西你怎麼弄丟了!!");
    command("say 幸好這東西若非我傳授使用方法，是無法使用的，我再拿一個給你吧。");
    new("/open/magic-manor/obj/magic-sign")->move(this_player());
    return "下次記得小心些，別再弄丟了!!";
  }

  if(present("magic sign",me) && me->query("quests/can_go_magic-manor"))
  {
    command("say 聚靈引已經給你了，好好使用吧，切莫遺失了。");
    return "聚靈山莊的入口位置就在風雲鎮東方不遠處的密林內。\n";
  }
  else if( me->query_temp("quests/magic-maonr-02") > 2 )
  {
    return "先把我交待的任務完成吧!!";
  }
  else if( me->query_temp("quests/magic-maonr-02") && me->query_temp("quests/magic-maonr-02") <= 2 )
  {
    return "看來你知道的不少了，醉問天也真是的，說這麼多作什麼 ...@#$Q%";
  }
  else
  {
    return "無端端的問我這做什麼，快滾開!!\n";
  }
}

string magic_manor2()
{
  object me;
  me=this_player();

  if( me->query("quests/can_go_magic-manor") )
  {
    return "最近山莊真是變化好大，好想回去一趟看看呀!!";
  }
  else if( me->query_temp("quests/magic-manor-02") == 2 )
  {
    me->set_temp("quests/magic-manor-02",3);
    return "聚靈山莊鮮少在江湖上活動，所以知道的人有限。\n"
      +"            不瞞你，我也曾是聚靈山莊的一份子。\n"
      +"            如果你想要進入聚靈山莊，我可以助你一輩之力。\n"
      +"            不過......你要先替我完成三件事才行。\n";
  }
  else
  {
    return "聚靈山莊，傳說是個神秘的地方，我知道的也不多!!";
  }
}

string magic_manor3()
{
  object me;
  me=this_player();

  if( me->query("quests/can_go_magic-manor") )
  {
    return "多虧你完成這三件事，讓聖火教在江湖的地位又更加崇高了。\n";
  }
  else if( me->query_temp("quests/magic-manor-02") == 3 )
  {
    command("hmm");
    call_out("three_check1",3,me);
    return "待我想一下，要讓你完成的三件事。\n";
  }
  else if( me->query_temp("quests/magic-manor-02") && me->query_temp("quests/magic-manor-02") < 3 )
  {
    return "嘿嘿，你的進度也未免太快了吧!!\n";
  }
  else
  {
    return "什麼三件事呀，聽不懂啦!!\n";
  }
}

int three_check1()
{
  object me,ob;

  me=this_player();
  ob=this_object();

  if( me->query_temp("quests/magic-manor-02") == 3 && !me->query("quests/can_go_magic-manor") )
  {
    command("say 好了，我想好了!!");
    command("say 第一件事情：傳說長白山有一個千年樹妖，請你帶回他的一片樹葉。");
    command("say 此妖的法術非常厲害，連我都敗在他手下。");
    command("say 等你拿到了，我再告訴你第二件事情吧!!");
    me->set_temp("quests/magic-manor-02",4);
  } else {
    command("say 嗯!!");
  }
  return 1;
}

int three_check2()
{
  object me,ob;

  me=this_player();
  ob=this_object();

  if( me->query_temp("quests/magic-manor-02") == 5 && !me->query("quests/can_go_magic-manor") )
  {
    command("say 好了，我想好了!!");
    command("say 第二件事情：蛇寨寨主的項上人頭。");
    command("say 據說此人生性殘暴，是非不分，佔據蛇寨為王，還四處姦淫擄掠，無惡不作。");
    command("say 等你拿到了，我再告訴你第三件事情吧!!");
    me->set_temp("quests/magic-manor-02",6);
  } else {
    command("say 嗯!!");
  }
  return 1;
}

int three_check3()
{
  object me,ob;

  me=this_player();
  ob=this_object();

  if( me->query_temp("quests/magic-manor-02") == 7 && !me->query("quests/can_go_magic-manor") )
  {
    command("say 好了，我想好了!!");
    command("say 這是最後一件了：我要一個焚天魔王的人頭。");
    command("say 魔界的王者之王，如果你能打敗他，足證明你的能力。");
    command("say 就等你的好消息了!!");
    me->set_temp("quests/magic-manor-02",8);
  } else {
    command("say 嗯!!");
  }
  return 1;
}

int magic_sign()
{
  object me,obj;

  me=this_player();

  if( me->query_temp("quests/magic-manor-02") == 9 && !me->query("quests/can_go_magic-manor") )
  {
    command("say 我出的三件事其實是要考驗你的能耐、品性和合群性的。");
    command("say 聚靈山莊正需要像你這樣的人材，我果真是沒有看錯你。");
    command("say 這塊聚靈引，就交給你了，使用的方法很簡單，我這就教你.......。");
    command("say 這樣子你懂了吧，只要走在正確的位置，它就會引導你了。");
    me->delete_temp("quests/magic-manor-01");
    me->delete_temp("quests/magic-manor-02");
    me->set("quests/can_go_magic-manor",1);
    obj=new("/open/magic-manor/obj/magic-sign");
    obj->move(me);
    message_vision("林昇宏交給$N一塊$n。\n",me,obj);
    command("say 接下來我再傳一點功\力給你吧!!");
    command("say 希望你能為聚靈山莊多盡一點心力。");
    me->start_busy(15);
    message_vision(HIY"林宏昇將雙手置於$N百會與膻中兩大穴，一股內勁由林宏昇的手掌鑽入$N體內。\n"NOR,me);
    call_out("trans_force",10,me);
  } else {
    command("say 嗯!!");
  }
  return 1;
}

int trans_force()
{
  object me;
  int force;
  me=this_player();
  force=me->query_skill("force",1);
  {
    message_vision(HIY"只見林宏昇臉頰上滿是汗水，不一會兒，行功\完畢。\n"NOR,me);
    tell_object(me,HIC"你只覺全身精氣神飽滿，身上的筋脈豁然貫通，內力更是有所長進。\n"NOR);
    me->set_skill("force",force+30);
    me->delete_busy();
  }
  return 1;
}

int accept_object(object me,object ob)
{
  int om,ot;
  me=this_player();
  om=ob->query("magic-manor");
  ot=me->query_temp("quests/magic-manor-02");

  if(me->query_temp("find_scroll") == 4 && ob->query("id") == "universe-book")
  {
    message_vision(HIW"\n$N將尋回秘笈的經過完完整整的向$n報告。\n"NOR,me,this_object());
    command("hmm");
    call_out("supertengin",5,me);
    return 1;
  }

  if(ob->query("id") == "purple-crystal" || ob->query("id") == "ice-crystal" ||
     ob->query("id") == "pink-crystal" || ob->query("id") == "sepia-crystal")
  { 
    if(me->query_temp("find_crystal") == 18)
    {
      if(ob->query("id") == "purple-crystal")
      {
        me->set("find_purple",1);
        command("say 唔...這的確是我教遺失許\久的紫水晶。");
      }
      if(ob->query("id") == "ice-crystal")
      {
        me->set("find_ice",1);
        command("say 唔...這的確是我教遺失許\久的冰水晶。");
      }
      if(ob->query("id") == "pink-crystal")
      {
        me->set("find_pink",1);
        command("say 唔...這的確是我教遺失許\久的霞水晶。");
      }
      if(ob->query("id") == "sepia-crystal")
      {
        me->set("find_sepia",1);
        command("say 唔...這的確是我教遺失許\久的褐水晶。");
      }
    }
    if(me->query("find_purple") && me->query("find_ice") && me->query("find_pink") && me->query("find_sepia"))
    {
      command("spank "+me->query("id"));
      command("say 太好了!!想不到你真的找齊了失落的渾天水晶");
      
      if(me->query_temp("find_scroll") && me->query_temp("adv_prayer"))
      {
        command("say 恰好老夫剛跟陸老道約好討論先天乾坤功\正卷的事宜，你趕快去找他吧!!");
        me->set_temp("find_scroll",2);
      }
    }
  }
  if( !ot )
  {
    if( om == 2 )
    {
      command("say 這封信是那來的呀？看來你也非是善良人仕!!");
      command("say 就讓本教皇為武林除害吧!!");
      destruct(ob);
      kill_ob(me);
    } else {
      command("say 本教皇正在忙!!   去! 去!! 去!!!");
      destruct(ob);
      return 0;
    }
  } else {
    if( ot == 1 && om == 2)
    {
      command("say 嗯，這封信大有來歷，是醉問天親筆所寫的沒錯!!");
      command("say 能讓醉問天看的起的人，看來你的本事可不小喔!!");
      command("say 說吧！你來找我是不是想問有關聚靈山莊的事呀？");
      destruct(ob);
      me->set_temp("quests/magic-manor-02",2);
      return 1;
    } else if( ot == 4 && om == 3 && me->query_temp("quests/kill-dance") == 1 )
    {
      me->set_temp("quests/magic-manor-02",5);
      me->delete_temp("quests/kill-dance");
      command("hmm");
      destruct(ob);
      call_out("three_check2",3,me);
      return 1;
    } else if( ot == 4 && om == 3 && me->query_temp("quests/kill-dance") != 1 )
    {
      command("say 看你一副精神飽滿的樣子，這片葉子不是你親手拿到的吧？");
      destruct(ob);
      return 1;
    } else if( ot == 6 && om == 4 && me->query_temp("quests/kill-snake") == 1 )
    {
      me->set_temp("quests/magic-manor-02",7);
      me->delete_temp("quests/kill-snake");
      command("hmm");
      destruct(ob);
      call_out("three_check3",3,me);
      return 1;
    } else if( ot == 6 && om == 4 && me->query_temp("quests/kill-snake") != 1 )
    {
      command("say 這個......蛇郎君不是你親手殺死的吧？");
      destruct(ob);
      return 1;
    } else if( ot == 8 && om == 5 )
    {
      me->set_temp("quests/magic-manor-02",9);
      call_out("magic_sign",1,me);
      destruct(ob);
      return 1;
    } else {
      command("say 我現在又沒有要這個東西，你拿給我做什麼？");
      destruct(ob);
    }
  }
  return 1;
}

string fist_book()
{
  object me = this_player();
  if(me->query_temp("ask_fist"))
  {
    me->set_temp("know_fist",1);
    command("think");
    return "這麼說是英雄正宗告訴你的嗎!?看來他真的不死心，不過無垢禪師已把無雙拳的
            秘笈交給我隱居已久的師叔了，他武功\比我強得太多，目前人在聚靈山莊內，
            有他守著，英雄正宗再厲害也沒辦法逞兇了。\n";
  } else {
    command("stare "+ me->query("id"));
    return "????你什麼都不知道!?別亂問喔!!";
  }
}

string magic_palace()
{
  object me = this_player();
  if(present("New_Hero Book",me) && me->query_temp("ko_baby"))
  {
    command("spank "+ me->query("id"));
    me->set_temp("enter_palace",1);
    return "我果然沒看錯人，不過魔宮的詳細位置我也不是很清楚，
            只聽說它位於人魔交界之處，在那裡可以看到天空中同時
            浮現三個太陽的奇景。\n";
  } else {
    message_vision(HIW"你果然跟天嬰是一夥的!!殺!!!!!!\n"NOR,me);
    kill_ob(me);
    return "殺殺殺!!";
  }
}

string adv_prayer()
{
  object me = this_player();
  if(present("white-crystal",me) && present("black-crystal",me) && present("blue-crystal",me) &&
     present("yellow-crystal",me) && present("red-crystal",me)  && present("green-crystal",me))
  {
    command("hmm");
    me->set_temp("adv_prayer",1);
    call_out("adv_prayer0",20,me);
    return "看到這幾根水晶聚集在一起，又讓我想起多年時的一段回憶";
  }
  else if(me->query("class") == "prayer")
  {
    return "先去把所有水晶都拿來吧。";
  } else {
    command("say 格老子的!!  覬覦我教絕學!?  去死吧!!");
    kill_ob(me);
    command("perform force.bluesea3");
    return "殺殺殺!!";
  }
}

int adv_prayer0()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)== environment())
  {
    command("say 你應該早已知道，本派為周武王姬發所創，向來以身負洛書河圖武學的神聖武學自傲。");
    command("say 武功\則分為兩大派系，一為$HIC$河圖系$HIY$的先天乾坤功\，一為$HIG$洛書系$HIY$的渾天寶鑑。");
    call_out("adv_prayer1",30,me);
  }
  return 1;
}

int adv_prayer1()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)== environment())
  {
    command("say 因本派為武林正道之最後防線，因此弟子遴選特別謹慎，代代向來只有單一嫡系傳人。");
    command("say 直至數十年前魔界入侵人間，老夫領導正道各派群起反擊之際，本門總壇竟遭夜夢雙妖強襲。");
    call_out("adv_prayer2",30,me);
  }
  return 1;
}

int adv_prayer2()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 夜夢雙妖在老夫眼裡本不足為懼，即便當時守壇的嫡傳弟子'浪清心'，亦可在公平對戰下樂勝。");
    command("say 然其合璧之『太陰虛幻神鑑』竟似處處克制我教武學，加以雙拳難敵四手，清心最後終於慘敗。");
    call_out("adv_prayer3",30,me);
  }
  return 1;
}

int adv_prayer3()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 但凡本派傳人便沒可能空手赴死，清心於彌留之際領悟最終境界，終於融合洛書系、河圖系的兩大神功\。");
    command("say 本皇接獲通報趕回總壇之時，適逢清心施展「雷兮血穹蒼」，此招一出，夜夢雙妖立成肉醬。");
    command("say 然而清心終究回天乏術，雙妖一死，清心亦同時爆體而亡。");
    command("say 本皇痛失愛徒之餘，立誓有朝一日必血洗魔界，從此大開門戶，廣收弟子，便有今天這番興盛。");
    if(me->query_temp("adv_prayer") == 1) me->set_temp("adv_prayer",2);
  }
  return 1;
}

string ask_universe()
{
  object me = this_player();
  if (environment(me)==environment())
  {
    command("say 河圖系為黃帝於逐鹿之戰所用以擊敗蚩尤的武學，黃帝死後，由廣成仙派繼承其精隨。");
    command("say 之後的傳人，東周姬太子丹，因妄使奧義『天驚地動』塗炭生靈，最後慘遭天譴身亡。");
    command("say 幸而當時的天道派創始者「玄清子」陸清陽乃太子丹座下食客之一。");
    command("say 因此得以謄寫一份副本保留了下來，此副本後來即成為我教的主要武學之源。");
    if(me->query_temp("adv_prayer") == 2) me->set_temp("find_scroll",1);
 }
  if(me->query_temp("find_scroll") && me->query_temp("find_crystal") && me->query_temp("adv_prayer") == 2)
  call_out("both_skill0",30,me);
  return "這就是先天乾坤功\的由來。";
}

string ask_superforce()
{
  object me = this_player();
  if (environment(me)==environment())
  {
    command("say 洛書系的渾天寶鑑則為女媧補天，力竭而亡前，將其對最終境界的領悟刻於渾天水晶上之驚世武學。");
    command("say 這十根渾天水晶即為西周時期雄遽一方的縹緲城之武學源頭。及後因與周武王之戰而下落不明。");
    command("say 直到近百年前，才由當時的鏡月島島主「九霄玄女」月無垠發現其中六根，而輾轉交還我派。");
    if(me->query_temp("adv_prayer") == 2) me->set_temp("find_crystal",1);
  }
  if(me->query_temp("find_scroll") && me->query_temp("find_crystal") && me->query_temp("adv_prayer") == 2)
  call_out("both_skill0",30,me);
  return "這就是渾天寶鑑的由來。";
}


int both_skill0()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 旦你不覺得很奇怪嗎，本教歷代奇人輩出，何以無一能像先祖周武王和清心般完美融合洛書、河圖兩系的絕學。");
    command("say 本皇好奇之際，便派遣八天門門主暗中到中土展開調查，欲尋訪失傳已久的先天乾坤功\正卷和遺落的渾天水晶。");
    call_out("both_skill1",30,me);
  }
  return 1;
}

int both_skill1()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 世事無常，竟發現鏡月島的魔法「夢玄法鑑」和夜夢雙妖的「太陰虛幻神鑑」本為同源。");
    command("say 加以鏡月、夜夢同喜以眩人的舞姿擾敵，本皇懷疑鏡月島匿藏水晶且暗中串通魔界，遂立刻傾全教之力圍攻鏡月島。");
    call_out("both_skill2",30,me);
  }
  return 1;
}

int both_skill2()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 血戰歷時半旬，最後只剩我和月半彎對峙時，隱居以久的寂元子師叔和前鏡月島島主嫵情生竟連抉現身，");
    command("say 同時發動玄宇宙的化劫和太陰虛幻神鑑所載之水月神鏡第三重，將穹蒼無悔和地獄雷火雙雙壓下。");
    command("say 一場大戰，就在雙方前輩的秘密協商之下暫時落幕，我們亦回到總部調養生息，然而尋找武學正源的行動並未因而停擺\...");
    if(me->query_temp("find_crystal") == 1)  me->set_temp("find_crystal",2);
  }
  return 1;
}

int supertengin()
{
  object ob = this_player();
  command("say 想不到清心雖死，仍然對本教安危念念不忘。");
  command("cry");
  call_out("supertengin2",5,ob);
  return 1;
}

int supertengin2()
{
  object ob = this_player();
  message_vision(HIY"\n$N收拾起悲傷的情緒。\n"NOR,this_object());
  command("say 既然你親眼見到清心的戰鬥，那麼對於本教武學奧義應該有了更深的領悟吧。");
  message_vision("\n(perform force.supertengin)\n",ob);
  ob->set("advance_prayer",1);
  call_out("supertengin3",7,ob);
  return 1;
}

int supertengin3()
{
  object ob = this_player();
  command("say 因此我正式宣布，從現在開始，你就是本教下一任教主。");
  ob->set("title",HIW"新"HIM"‧"RED"聖火"HIY"教皇"NOR);
  call_out("supertengin4",7,ob);
  return 1;
}

int supertengin4()
{
  object me = this_player();
  tell_object(users(),HIG"武林沉浮數十載，本皇終於有了新一代的接班人，

    "+me->query("name")+"以後將會以本皇傳人的身分繼續領導武林正道，

      有朝一日定能血洗魔界，將焚天火王這老賊給徹底剷除!!!!
   \n"NOR);
  return 1;
}
