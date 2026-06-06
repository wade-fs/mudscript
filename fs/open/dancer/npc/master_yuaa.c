//master_yua.c 
//cgy
//把heart beat的conjure reflection拿掉..改成temp設定..
//加入聖火進階解謎要素    by frequency 2003 May
//排版 與增加雷魂的紀錄 by blazakira 2011/10/18

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

string magic();
string ask_get_fdragon();
string ask_crystal();
string ask_moon();
string ask_crystal10();

void create()
{
  set_name("月半彎",({"master yuaa","yuaa"}));
  set("long","她是夜夢小築上任宮主,也是現任宮主月牙兒的姊姊。\n");
  set("gender","女性");
  set("class","dancer");
  set("nickname","朝霞仙子");
  set("combat_exp",7000000);
  set("attitude","heroism");
  set("age",20);
  set("str", 38);
  set("cor", 35);
  set("cps", 50);
  set("per", 40);
  set("adv_dancer",1);
  set("allow_hellfire",1);
  set("int", 40);
//  set("kee",50000);
  set("max_kee",50000);
//  set("gin",30000);
  set("max_gin",30000);
//  set("sen",30000);
  set("max_sen",30000);
  set("atman",20000);
  set("max_atman",20000);
  set("mana",4000);
  set("max_mana",4000);
  set("force",20000);
  set("max_force",20000);
  set_skill("array",60);
  set_skill("parry",60);
  set_skill("spells",50);
  set_skill("magic",130);
  set_skill("cure",60);
  set_skill("force",60);
  set_skill("literate",70);
  set_skill("move",100);
  set_skill("dodge",100);
  set_skill("sword",50);
  set_skill("unarmed",70);
  set_skill("paull-steps",130);
  set_skill("dremagic",100);
  set_skill("dreamforce",100);
  set_skill("dreamdance",100);
  set("no_poison",1);
  set("no_askgod",1);
  map_skill("magic","dremagic");
  map_skill("dodge","paull-steps");
  map_skill("force","dreamforce");
  map_skill("move","paull-steps");
  map_skill("unarmed","dreamdance");
  set_temp("apply/armor",70);
  set_temp("apply/dodge",20);
  set_temp("ref_shield",1);
  set("get_dan_sp",1);
  set("/spells/reflection/level",100);
  set("/spells/confuse/level",100);
  set("/spells/fireball/level",100);
  set("/spells/thunder/level",100);
  set("/spells/hellfire/level",75);
  set("/spells/firedance/level",100);
  set("/spells/dreamcure/level",100);
  set("/spells/dreamwings/level",100);
  set("force_factor",30);
  set("ann_die",1);
  setup();
  create_family("夜夢小築",2,"宮主");
  carry_object("/open/dancer/obj/yuacloth.c")->wear();
  carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
  carry_object("/open/dancer/obj/yuawaist.c")->wear();
//  add_money("diamond",2)
  set("inquiry", ([
    "傅劍寒"      : "你說的是神龍山莊莊主傅劍寒嗎??他是我傾慕的偶像耶!!",
    "水月神鏡"    : "我見過嫵師伯使用過此招的最高功\力，但她總對此事三緘其口。",
    "聚靈山莊"    : "那是一個江湖中鮮為人知的地方，我也不曾去過。",
    "嫵師伯"      : "她在聚靈山莊內隱居好一段時間了。",
    "凌師姐"      : "她幾年前因心術不正遭到驅逐，可惜她一身超越凌師伯的資質。據說曾在長白山出沒。",
    "炎之龍"      :  (: ask_get_fdragon :),
    "可惜"        :  (: ask_crystal10 :),
    "渾天水晶"    :  (: ask_crystal :),
    "太陰虛幻神鑑":  (: ask_moon :),
  ]));
  set("chat_chance_combat",60);
  set("chat_msg_combat",({
    (: magic :),
  }));
}

void init()
{
  set_heart_beat(1);
}

void heart_beat()
{
//  object me=this_object();
  :: heart_beat();

  if( is_fighting() ) {
    if(is_busy()) {
      delete_busy();
      message_vision(HIW+"\n月半彎笑道：想定住我??門都沒有。\n"+NOR,this_object());
    }
    if(random(100)>85)
    {
      command("conjure hellfire");
    }
  }
  else {
    if( query("sen") < query("eff_sen") ) // 125
      command( "exert refresh" );
    if( query("eff_kee") < query("max_kee") )
      command("conjure dreamcure");
  }

//  return;
}

string ask_get_fdragon()
{
  if(this_player()->query("spells/fdragon/level"))
    return "妳不是學過了？？";
  if(this_player()->query("class")!="dancer")
  {
    command("stare"+this_player()->query("id"));
    return "妳問那麼多幹嘛？";
  }
  this_player()->set_temp("ask_fdragon",1);
  return "想學炎之龍??先打贏我再說吧!!";
}

int accept_object(object who,object ob)
{
  string ob_id;
  ob_id=ob->query("id");

  if(ob_id=="king's letter")
  {
    command("say 原來是皇上派你來的....\n");
    command("sigh");
    command("say 好吧..你幫我把這封信拿給皇上他就知道了....\n");
    new("/open/dancer/obj/letter2")->move(this_player());
    this_player()->set_temp("ask_moon7",1);
  }
  return 1;
}

string magic()
{
  command("conjure confuse");
  command("conjure fireball");
  command("conjure reflection");
  command("conjure firedance");
  command("conjure thunder");
  command("conjure dreamwings");
  return "\n";
}

int accept_fight(object ob)
{
  command("say 小女子怎是您的對手呢??\n");
  command("conjure reflection");
  command("conjure dreamwings");
  command("conjure confuse");
  message_vision( this_object()->name()+"一付弱不禁風的樣子。\n",ob);
  return 1;
}

int accept_kill(object ob)
{
  command("say 沒想到你忍心欺負弱小女子，那我就不客氣了!!\n");
  command("conjure reflection");
  command("conjure dreamwings");
  command("conjure confuse");
  return 1;
}

void die()
{
  object ob,spirit;
  ob=query_temp("last_damage_from");

  if( random(144) == 77 )
  {
    spirit = new("/open/ghost-hole/obj/thunder-spirit");
    spirit->move(ob);
    log_file("sky/spirit/thunder-spirit",sprintf("%s(%s)讓月半彎掉下了%s於 %s\n",ob->name(1),ob->query("id"),spirit->query("name"),ctime(time())));
    message_vision(HIW"薀含在"+this_object()->query("name")+HIW"身體中的"+spirit->query("name")+HIW"飛射而出，落在$N"HIW"手中。\n"NOR,ob);
  }

  if( ob->query("class")=="dancer" && ob->query_temp("ask_fdragon"))
  {
    tell_room(environment(ob),HIY"月半彎說：看來"+ob->name()+"的確有這個能力學習炎之龍！\n"NOR);
    ob->set("spells/fdragon/level",1);
    ob->set("allow_fdragon",1);
    message("system",HIM"月半彎高興的說道：恭喜"HIW""+ob->name()+""HIM"通過考驗成為"HIR"炎ソ舞者。\n"NOR,users());
    ob->set("title",HIW"【"HIR"炎ソ舞者"HIW"】"NOR);
  }
  else
  {
  if( ob )
    set_temp("die",HIC"\n"+query("name")+"說：想不到你的武功\如此厲害。\n\n"NOR);
//    tell_room(environment(ob),HIC"月半彎說：想不到妳的武功\如此厲害。\n"NOR);
  }
  ::die();
}

string ask_crystal()
{
  object me = this_player();
  if(me->query_temp("find_crystal") >= 4)
  {
    call_out("ask_crystal1",40,me);
    return "想不到師妹都告訴你了啊，唉......\n";
  }
  else if(me->query("class") == "prayer")
  {
    return "什麼水晶火晶啊，不知道啦!!";
  }
  else
  {
    command ("say 不是聖火教的問啥問啊!?去死吧！");
    kill_ob(me);
    command("conjure hellfire");
    return "殺殺殺!!";
  }
}

string ask_moon()
{
  object me = this_player();
  if(me->query_temp("find_moon"))
  {
    if(me->query_temp("find_moon") == 2) me->set_temp("find_moon",3);
    return "其實這魔法還蠻不錯的，據說嫵師伯從跟夜夢雙星的戰鬥中領悟了水月神鏡的更深一層奧秘。";
  }
  else if(me->query("class") == "prayer")
  {
    return "什麼太虛太監的，不知道啦!!";
  }
  else if(me->query("class") == "dancer")
  {
    return "威路古‧扎基爾夫說現在還不能解哩，請回吧。";
  }
  else
  {
    command ("say 不是聖火教和本門的人問啥問啊!?去死吧！");
    kill_ob(me);
    command("conjure hellfire");
    return "殺殺殺!!";
  }
}

int ask_crystal1()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("sigh");
    command("say 說來話可長了，這一切的一切，都得回到祖師爺的時代說起。");
    call_out("ask_crystal2",15,me);
    if(me->query_temp("find_crystal") == 4) me->set_temp("find_crystal",5);
  }
  return 1;
}

int ask_crystal2()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("sigh");
    command("say 先祖「九霄玄女」月無垠的確是尋回了所有的渾天水晶，原本亦打算盡數交還給貴派。");
    call_out("ask_crystal3",10,me);
    if(me->query_temp("find_crystal") == 5) me->set_temp("find_crystal",6);
  }
  return 1;
}

int ask_crystal3()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 不料風聲走漏，引來焚天火王的覬覦，因而派遣十八魔將，在水晶交接的前一天，趁夜前來搶奪。");
    call_out("ask_crystal4",10,me);
    if(me->query_temp("find_crystal") == 6) me->set_temp("find_crystal",7);
  }
  return 1;
}

int ask_crystal4()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 先祖法力之深厚，實已達超凡入聖之境，甫開戰已將十八魔將斬其十一，豈料竟是調虎離山之計。");
    call_out("ask_crystal5",10,me);
    if(me->query_temp("find_crystal") == 7) me->set_temp("find_crystal",8);
  }
  return 1;
}

int ask_crystal5()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 手操失傳遠古魔法『太陰虛幻神鑑』的夜夢雙妖，竟趁十八魔將猛攻的同時，衝入島內重地搶奪水晶。");
    call_out("ask_crystal6",10,me);
    if(me->query_temp("find_crystal") == 8) me->set_temp("find_crystal",9);
  }
  return 1;
}

int ask_crystal6()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 幸而先祖即時察覺，回身追殺雙妖，雙妖亦施展太陰虛幻神鑑之水月神鏡，阻擋先祖追擊，趁機脫逃。");
    call_out("ask_crystal7",10,me);
    if(me->query_temp("find_crystal") == 9) me->set_temp("find_crystal",10);
  }
  return 1;
}

int ask_crystal7()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 大戰過後，清點水晶，發現其中四根已被奪走，先祖生性高傲，對此引以為恥，因而對外宣稱僅尋獲六枚水晶。");
    call_out("ask_crystal8",10,me);
    if(me->query_temp("find_crystal") == 10) me->set_temp("find_crystal",11);
  }
  return 1;
}

int ask_crystal8()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 然而先祖畢竟對遺失水晶感到內疚，因此立下規矩，自她以後，歷代島主務必全力奪回水晶，以免威名受辱。");
    call_out("ask_crystal9",10,me);
    if(me->query_temp("find_crystal") == 11) me->set_temp("find_crystal",12);
  }
  return 1;
}

int ask_crystal9()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 前代掌門嫵師伯乃百年難得一見之天才，竟當真遠赴魔界，由雙妖傳人--夜夢雙星手中奪回水晶，可惜...");
    if(me->query_temp("find_crystal") == 12) me->set_temp("find_crystal",13);
  }
  return 1;
}

string ask_crystal10()
{
  object me = this_player();
  if(me->query_temp("find_crystal") == 13) me->set_temp("find_crystal",14);
  call_out("ask_crystal11",10,me);
  return "可惜她回來路上，遭凌師姐暗算，剛到手的水晶又被劫走，更因而受到重傷，只好傳位於我，到聚靈山莊靜養";
}

int ask_crystal11()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 所以當貴派林教主到本門興師問罪的時候，我亦對於代代尋找水晶的任務與犧牲重大感到不耐。");
    command("say 不是我闖出的禍我亦不屑解釋，遂全面開戰。幸而最後關頭由寂元子和痊癒的嫵師伯調停，否則必定兩敗俱傷。");
    if(me->query_temp("find_crystal") == 14) me->set_temp("find_crystal",15);
    call_out("ask_crystal12",10,me);
  }
  return 1;
}

int ask_crystal12()
{
  object me = this_player();
  if(!me) return 1;
  if (environment(me)==environment())
  {
    command("say 然而對於水晶一事，仍然一直未向貴派解釋，因此林教主仍不知水晶去向，妹子亦努力尋找凌師姐下落。");
    command("say 這就是一切事情的經過了。");
    if(me->query_temp("find_crystal") == 15) me->set_temp("find_crystal",16);
  }
  return 1;
}
