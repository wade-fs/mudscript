//修正信件不會交給玩家的問題(改用new->玩家身上) 並額外做信件遺失的判定 by blazakira 2011/4/10

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void do_wield();
string do_linpo();
string do_sp();

string GetGlobalQuestName (string QuestMark);
string GetGlobalQuestDescription (string QuestMark);

mapping *MissionList = ({
([
  "Index"       : 1,
  "QuestMark"   : "quests/sale_girl",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 2,
  "QuestMark"   : "quests/bento",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 3,
  "QuestMark"   : "quests/stone",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 4,
  "QuestMark"   : "quests/find_dguger",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 5,
  "QuestMark"   : "quests/bochen_trouble",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 6,
  "QuestMark"   : "quests/gamble_book",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 7,
  "QuestMark"   : "quests/catch_thief",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 8,
  "QuestMark"   : "quests/poison_help",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 9,
  "QuestMark"   : "quests/lotch",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 10,
  "QuestMark"   : "quests/badman_license",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 11,
  "QuestMark"   : "quests/blade_out",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 12,
  "QuestMark"   : "quests/get_tiger",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 13,
  "QuestMark"   : "quests/fear_fighting",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 14,
  "QuestMark"   : "quests/dragon-kee",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 15,
  "QuestMark"   : "quests/sec_god",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 16,
  "QuestMark"   : "quests/peach",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 17,
  "QuestMark"   : "quests/ya",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 18,
  "QuestMark"   : "quests/acupuncture",
  "QuestName"   : "衝穴之迷",
  "Description" : "
  傳說中，這項技能可以讓人在戰鬥中，衝破被封鎖的
  穴道，武林中很多人對此項技能非常眼紅，有不少門
  派在密尋這個技能
",
]),
([
  "Index"       : 19,
  "QuestMark"   : "quest/dragon",
  "QuestName"   : "幫助柳繪心",
  "Description" : "柳家鏢局第二掌門，需要人來幫忙報仇，你能夠幫他完成心願嗎？",
]),

([
  "Index"       : 20,
  "QuestMark"   : "quests/ice-frog",
  "QuestName"   : "冰蟾丹元",
  "Description" : "據說服用了冰蟾丹元之後，可以提升內功\修為，但是一生只能吃一次",
]),
([
  "Index"       : 21,
  "QuestMark"   : "quests/moon",
  "QuestName"   : (: GetGlobalQuestName :),
  "Description" : (: GetGlobalQuestDescription :),
]),
([
  "Index"       : 22,
  "QuestMark"   : "quest/save_yan",
  "QuestName"   : "解救風青雲",
  "Description" : "仙劍派掌門鄭士欣的師叔風青雲失蹤很久了，你能找到他嗎？",
]),

([
  "Index"       : -1,
  "QuestMark"   : "End",
  "QuestName"   : "End",
  "Description" : "End",
]),

});

mixed ListMission ();

mixed *msg_hand=({
    "say 好，我現在就把絕招傳給你。",
    "say 此絕招，是我融合臨書點穴之術和凌波微步的精華所創出來的。",
    "say 將兩種招式融合為一之後，可以在戰鬥中，快速的移動，點人穴道。",
    "say 不過我練到現在，最多也只能一次連封四人的穴道而已。",
    "say 我現在就將步法傳授給你，看清楚了!!",
    "msg" + HIG + "只見$N腳踩奇步，繞著$n" + HIG + "不停的移動，$n" + HIG + "凝神去看，仍看得非常吃力。\n" + NOR,
    "msg" + HIG + "$N終於停了下來。\n" + NOR,
    "say 如何，應該看懂了吧!",
    "say 這絕招當然不是你這樣看了看就能馬上通曉的，只有不斷的在戰鬥中累積經驗，才有融會貫通的一日。",
    "say 當然，招式越熟練，在戰鬥中對你的幫助也就越大。",
    "say 好好利用這個絕招，多做一些行俠仗義的事情吧。",
    "end",
});
mixed *msg_six_pre=({
    "say 你竟然知道六脈神劍的絕招?",
    "sigh",
    "say 近來邊關外的ㄧ些叛徒屢屢侵犯我們，的確是該將六脈神劍的絕招傳授下去。",
    "say 但是我得看你是不是有資格將六脈神劍的絕招發揚光大。",
    "end",
});

string
GetGlobalQuestName (
  string QuestMark
)
{
  mapping quests;
  string  *k;
	int     i;

  quests = "/cmds/std/quests"->query_quests();
  k = keys(quests);
  for (i = 0; i < sizeof (quests); i++) {
    if (strcmp (quests[k[i]], QuestMark) == 0) {
      return k[i];
    }
  }
  return "unknow";
}

string
GetGlobalQuestDescription (
  string QuestMark
)
{
  mapping quest_long;

  quest_long = "/cmds/std/quests"->query_quest_long();
  return quest_long[GetGlobalQuestName(QuestMark)];
}

mixed ListMission ()
{
  object me;
  string Answer;
  string QuestMark;
  string QuestName;
  string QuestDescription;
  int Index;

  me = this_player();
  if (!me) return 0;
  if (!wizardp (me)) return 0;
  command ("quests");
  Answer = sprintf (HIY + "我知道的任務有 :\n");
  Answer += sprintf ("--------------------------------------\n");
  for (Index = 0; MissionList[Index]["Index"] != -1; Index++) {
    QuestMark = MissionList[Index]["QuestMark"];
    if (functionp (MissionList[Index]["QuestName"])) {
      QuestName = evaluate (MissionList[Index]["QuestName"], MissionList[Index]["QuestMark"]);
    }
    else {
      QuestName = MissionList[Index]["QuestName"];
    }
    if (functionp (MissionList[Index]["Description"])) {
      QuestDescription = evaluate (MissionList[Index]["Description"], MissionList[Index]["QuestMark"]);
    }
    else {
      QuestDescription = MissionList[Index]["Description"];
    }
    Answer += sprintf ("Mark : %s\nName : %s\nDescription : %s\n", QuestMark, QuestName, QuestDescription);
    Answer += sprintf ("--------------------------------------\n");
  }
  Answer += NOR;
  return Answer;
}

void SetNoAnswer ()
{
  set ("no_answer", 1);
  return;
}

int DeleteNoAnswer ()
{
  delete ("no_answer");
  return 1;
}

int six_msg2(object ppl)
{
  int i;
  object me;
  string Answer;
  string QuestMark;
  string QuestName;
  string QuestDescription;
  int Index;

  if(!ppl) return DeleteNoAnswer();
  if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
  me = ppl;
  command ("quests");
  for (Index = 0; MissionList[Index]["Index"] != -1; Index++) {
    QuestMark = MissionList[Index]["QuestMark"];
    if (ppl->query(QuestMark)) {
      continue;
    }
    if (functionp (MissionList[Index]["QuestName"])) {
      QuestName = evaluate (MissionList[Index]["QuestName"], MissionList[Index]["QuestMark"]);
    }
    else {
      QuestName = MissionList[Index]["QuestName"];
    }
    if (functionp (MissionList[Index]["Description"])) {
      QuestDescription = evaluate (MissionList[Index]["Description"], MissionList[Index]["QuestMark"]);
    }
    else {
      QuestDescription = MissionList[Index]["Description"];
    }
    Answer = "\n";
    command ("say 這裡有個任務要你來完成。");
    Answer += sprintf ("任務名稱：%s\n", QuestName);
    Answer += sprintf ("任務敘述：%s\n", QuestDescription);
    command ("say " + Answer);
    command ("say 先去完成這個任務再說吧。");
    return DeleteNoAnswer();
  }
  command ("say 好，你已經夠資格學習六脈神劍的絕招了。");
  Answer = sprintf ("
  你忽然感覺到段譽的眼神變得非常的深邃，你感到神智開始迷糊
  你忽然聽到段譽的聲音在你耳邊響起：
  我現在就把六脈神劍的絕招烙印在你的腦海裡，多多體會，把它發揚光大
  好好教訓那些叛徒們。

  你忽然感到頭部一陣刺痛，腦子裡好像多了些甚麼。
");
  tell_object (ppl, Answer);
  ppl->set("marks/six-fingers", 3);

  return DeleteNoAnswer();  
}

void create()
{
        set_name("段譽",({"duan yu","duan","yu"}));
        set("title",HBMAG+HIC + "六脈劍聖" + NOR);
        set("long","他可是第一位將六脈神劍融會貫通的人,他的六脈神劍已達爐火純青的
地步\n");
        set("gender","男性");
        set("combat_exp", 20000000);
        set("attitude","friendly");
        set("bellicosity",3000);
        set("family/family_name","段家");
        set("age",28);
        set("str", 99);
        set("cor", 99);
        set("cps", 99);
        set("per", 30);
        set("int", 99);
        set("food",1000);
        set("water",1000);
        set("force",100000000);
        set("max_force",50000000);
        set("kee",8000000);
        set("max_kee",8000000);
        set("gin",8000000);
        set("max_gin",8000000);
        set("sen",8000000);
        set("max_sen",8000000);
        set("chat_chance", 5);
        set("chat_msg", ({
        "段譽道: 唉!好不容易想出來的絕招，卻找不到傳人。\n",
        "段譽道: 自由自在的生活，真是太棒了。\n",
        }));
        set("inquiry", ([
        "凌波微步" : "那是我在瑯環福地的神仙姊姊那學到的步法，在打不過別人，要逃跑的時候最有用了!!\n",
        "步法" : "你要學凌波微步???真的想學的話去找段雲吧，我有把凌波微步的秘笈給他。\n",
        "武林浩劫" : "你自己去打聽吧，連這個都要問我，混什麼江湖?\n",
        "精華" : (: do_linpo :),
        "絕招" : (: do_sp :),
        "任務" : (: ListMission :),
        ]));
        set_skill("force",1000);
        set_skill("unarmed",277);
        set_skill("sunforce",238);
        set_skill("linpo-steps",100);
        set_skill("six-fingers",125);
        set_skill("parry",500);
        set_skill("dodge",500);
        set_skill("move",500);
        set_skill("stabber",277);
        set_skill("literate",150);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("unarmed","six-fingers");
        map_skill("stabber","six-fingers");
        set("force_factor",90);
        set("marks/six_sp",3);
        set("marks/six-fingers",3);
        set("marks/sun-finger",1);
        set("marks/linpo-steps",1);
        set("marks/handwriting",1);
        set("marks/fan-finger",1);
        set("marks/north-force",4);
        set_temp("apply/armor",300);
        set_temp("apply/stagger",50);
        set_temp("apply/defense",100);
        set_temp("apply/damage",120);
        set_temp("fan-finger",999999999);
        set("mpower",3);
        set("six_spsp",1);
        set("env/quick_fan","YES");
        set("env/fan_auto_shoot","YES");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
                (: perform_action("force.north-force") :),
                (: exert_function("threeforce") :),
        }));
        set("functions/handwriting/level",150);
        set("functions/threeforce/level",100);
        set("functions/fan-finger/level",120);
        set("functions/north-force/level",150);

        setup();
        carry_object(PING_OBJ"neck0")->wear();
        carry_object(PING_OBJ"cloud_fan");
        carry_object("/autoload/scholar/finger_fan");
        carry_object("/open/ping/questsfan/obj/diamond_armor")->wear();
        carry_object("/open/ping/questsfan/obj/diamond_belt")->wear();
        carry_object("/open/ping/questsfan/obj/diamond_boots")->wear();
        carry_object("/open/ping/questsfan/obj/diamond_cloak")->wear();
        carry_object("/open/ping/questsfan/obj/diamond_hairpin")->wear();
        carry_object("/open/ping/questsfan/obj/diamond_hands")->wear();
        carry_object("/open/ping/questsfan/obj/diamond_legging")->wear();
        carry_object("/open/ping/questsfan/obj/diamond_skirt")->wear();

        add_money("gold",100);
}
void init()
{
    call_out("do_wield",1);
    set_heart_beat (1);
}
void do_wield()
{
    command("wield all");
}
string do_linpo()
{
    object ppl;

    ppl=this_player();

    if(ppl->query("family/family_name") != "段家")
      return "嗯?你怎可能到得了這邊??";
    if(ppl->query("marks/ask_linpo")!=4)
      return "哈哈!易經精華之所在，可不是三言兩語就可以說盡的。";
    if(ppl->query_int() > 33) ppl->set_temp("teach_time",2);
    else ppl->set_temp("teach_time",4);
    SetNoAnswer();
    call_out("teach_step1",4,ppl);
    return HIY + "原來你是要學逃跑的技巧阿，哈哈，沒問題，我馬上表演一次給你看，看清楚了喔!!" + NOR;
}
string do_sp()
{
    object ppl;

    ppl=this_player();
    if(ppl->query("family/family_name") != "段家")
      return "嗯?你怎可能到得了這邊??";
    if(!ppl->query("marks/handwriting")){
      if(!ppl->query("marks/hand_steps")){
        command("say 你想要學絕招?");
        command("hmm");
        if(!ppl->query("marks/linpo-steps")){
          SetNoAnswer();
          call_out("sp_msg1",2,ppl);
          return "";
        }
        else{
          SetNoAnswer();
          call_out("sp_msg2",2,ppl);
          return "";
        }
      }
      else if(ppl->query("marks/hand_steps")==1){
        if(ppl->query("quests/ya")){
          SetNoAnswer();
          call_out("sp_msg3",2,ppl);
          return "";
        }
        else{
          return "快去完成我告訴過你的試驗吧!!\n";
        }
      }
      else if(ppl->query("marks/hand_steps")==2){
        if(ppl->query("marks/kill_fu")==2){
          SetNoAnswer();
          call_out("sp_msg6",2,ppl);
          return "";
        }
        else{
          if(!present("letter",ppl) || present("letter",ppl)->query("name")!="給慕容復的信") { //補充 by blazakira
            new("/open/tailong/obj/letter_1.c")->move(ppl);
            message_vision("$N給$n一封給慕容復的信。\n",this_object(),ppl);
          }
          return "我交待你的事，你還沒有完成吧??\n";
        }
      }
    }
    else{
      command("hmm");
      if (ppl->query_skill("six-fingers",1) < 100) {
        return "你連基本的六脈神劍都還沒學全，就想要學絕招喔？\n";
      }
      else {
        SetNoAnswer();
        call_out("six_msg1",10,ppl);
      }
      return "";
    }
}

int sp_msg1(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    command("say 要學絕招，必須先通過試驗，以你目前的能力，恐怕沒辦法過關!!");
    command("say 你先去把(凌波微步)學好再說吧。");
    return DeleteNoAnswer();
}

int sp_msg2(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    if(ppl->query("quests/ya")){
      ppl->delete("quests/ya");
      ppl->delete("go_ya");
    }
    command("say 最近武林中四處傳聞的「武林浩劫」，如果你能夠成功\的解決，就可以通過第一階段的試驗!!");
    if(ppl->query("marks/fan-finger"))
      command("say 既然你已經成功\的取得了飄陽扇，相信你可以成功\的完成任務!!");
    else{
      command("say 不過，你似乎還沒有取得飄陽扇，我建議你先去取得飄陽扇之後再去進行試驗。");
      command("say 當然這只是我的建議");
    }
    command("say 反正你記住一點，打不過，就要跑，知道嗎?");
    ppl->set("marks/hand_steps",1);
    return DeleteNoAnswer();
}
int sp_msg3(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    command("spank "+ppl->query("id"));
    command("果然沒有辜負我對你的期望，很好。");
    call_out("sp_msg4",4,ppl);
    return 1;
}
int sp_msg4(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    command("say 現在，只要你再完成我所交待你的這件事，我就會把絕招傳給你!!");
//    new("/open/tailong/obj/letter_1.c")->move(this_object());
//    command("give letter to "+ppl->query("id"));
    new("/open/tailong/obj/letter_1.c")->move(ppl);
    message_vision("$N給$n一封給慕容復的信。\n",this_object(),ppl);
    call_out("sp_msg5",3,ppl);
    return 1;
}
int sp_msg5(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    command("say 你只要將這封信交給慕容復即可。");
    command("say 西域天氣寒冷，把衣服穿夠了再去吧。");
    command("grin "+ppl->query("id"));
    ppl->set("marks/kill_fu",1);
    ppl->set("marks/hand_steps",2);
    return DeleteNoAnswer();
}
int sp_msg6(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    command("spank "+ppl->query("id"));
    command("say 太好了，終於幫我出了一口惡氣。");
    call_out("sp_msg7",4,ppl);
    return 1;
}
int sp_msg7(object ppl)
{
    int i;

    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();

    i=ppl->query("marks/msg_hand_steps");
    if(msg_hand[i][0..2]=="end"){
      ppl->set("marks/handwriting",1);
      ppl->delete("marks/hand_steps");
      ppl->delete("marks/kill_fu");
      ppl->delete("marks/kill_fu_fail");
      ppl->delete("marks/msg_hand_steps");
      return DeleteNoAnswer();
    }
    else if(msg_hand[i][0..2]=="msg"){
      message_vision(msg_hand[i][3..sizeof(msg_hand[i])-1],this_object(),ppl);
    }
    else{
      command(msg_hand[i]);
    }
    ppl->add("marks/msg_hand_steps", 1);
    call_out("sp_msg7",4,ppl);
    return 1;
}

//六脈二代技(奧義只能算是後三)
int six_msg1(object ppl)
{
    int i;

    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();

    i=ppl->query("marks/msg_six_steps");
    if(!ppl->query("marks/six-fingers")){
      if(msg_six_pre[i][0..2]=="end"){
        return six_msg2 (ppl);
      }
      else if(msg_six_pre[i][0..2]=="msg"){
        message_vision(msg_six_pre[i][3..sizeof(msg_six_pre[i])-1],this_object(),ppl);
      }
      else{
        command(msg_six_pre[i]);
      }
      ppl->add("marks/msg_six_steps", 1);
      call_out("six_msg1",4,ppl);
      return 1;
    }
    else {
      command ("say 該教你的絕招我都教給你啦！");
      return DeleteNoAnswer();
    }
}

int teach_step1(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    message_vision(HIC + "只見$N開始在$n" + HIC + "面前走來走去，$n" + HIC + "忽然眼睛一花，$N不見了!!\n" + NOR,this_object(),ppl);
    call_out("teach_step2",2,ppl);
    return 1;
}
int teach_step2(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    command("say 如何，看懂了嗎???");
    call_out("teach_step3",2,ppl);
    return 1;
}
int teach_step3(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    ppl->add_temp("teach_time",-1);
    if(ppl->query_temp("teach_time") > 0){
      ppl->do_command("shake");
      call_out("teach_step4",2,ppl);
      return 1;
    }
    else
    {
      ppl->do_command("nod");
      call_out("teach_step5",2,ppl);
      return 1;
    }
}
int teach_step4(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    command("say 看不懂阿，沒關係，我再做一次，看清楚囉!!");
    call_out("teach_step1",2,ppl);
    return 1;
}
int teach_step5(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    message_vision(HIG + "只見$N" + HIG + "開始在$n面前走來走去，$n忽然眼睛一花，$N" + HIG + "繞到了$n的背後!!\n",ppl,this_object());
    call_out("end_step",2,ppl);
    return 1;
}
int end_step(object ppl)
{
    if(!ppl) return DeleteNoAnswer();
    if(environment(this_object()) != environment(ppl)) return DeleteNoAnswer();
    command("haha");
    command("spank "+ppl->query("id"));
    command("say 幹得好，以後幾乎沒人可以奈何得了你了!!");
    command("say 不過有兩點要注意的!!");
    command("say 好漢不敵人多，所以千萬不要一對多，到時候跑不掉，死的就是你了");
    command("say 跑進了死胡同，逃跑的路徑少了，也就減少了你逃跑的機會");
    command("say 一定要注意這兩點，知道嗎?");
    ppl->set("marks/linpo-steps",1);
    ppl->delete("marks/ask_linpo");
    return DeleteNoAnswer();
}

void unconcious()
{
    message_vision("
$N忽然領悟" + HIC + "『凌波微步』" + NOR + "的要旨所在，腳步作到" + HIY + "「動無常則，若危若安，進止難期，
若往若還」" + NOR + ",霎時一片人影紛飛，讓敵人頭昏眼花\n",this_object());
    message_vision(HIC + "$N趁著這個機會逃離開這裡!!\n" + NOR,this_object());
    destruct(this_object());
}
void die()
{
    message_vision("
$N心中默念，將" + HIC + "『凌波微步』" + NOR + "的六十四卦步法，自「明夷」起始，經「賁」
 、「既濟」、「家人」，走了一大圈而至「旡妄」，終於順利擺\脫敵人的糾纏。\n" + NOR,this_object());
    message_vision(HIC + "$N趁著這個機會逃離開這裡!!\n" + NOR,this_object());
    destruct(this_object());
}
void heart_beat()
{
  mapping my;
  object  ob,room;

  my = this_object()->query_entire_dbase();

  if (!this_object()->is_fighting()) {
    if (my["eff_gin"] < my["max_gin"] ||
        my["eff_kee"] < my["max_kee"] ||
        my["eff_sen"] < my["max_sen"] ||
        my["gin"] < my["max_gin"] ||
        my["kee"] < my["max_kee"] ||
        my["sen"] < my["max_sen"] ||
        my["force"] < (my["max_force"] * 2)) {
      command ("perform force.north-force");
    } else if (this_object()->query("KillMystery")) {
      ob = find_living ("mystery swordsman");
      if(ob) {
        room = environment(ob);
      }
      if(!ob || !room) { 
        ob = find_living ("mystery shooter");
        if(ob) {
          room = environment(ob);
        }
      }
      if ((!ob || (ob && !room)) && this_object()->query("FoundMystery")) {
        this_object()->delete("FoundMystery");
        tell_object (users(),HIG + "
"+this_object()->query("name")+HIG + "高聲喝道：
你們這些自以為是的叛徒，別再讓我遇到，哼
\n" + NOR);
        this_object()->move("/open/tailong/room/d3");
      }
      else if (ob && !ob->is_fighting() && room) {
        if (!this_object()->query("FoundMystery")) {
          tell_object (users(),HIG + "
"+this_object()->query("name")+HIG + "高聲喝道：
又是你們這些自以為是的叛徒，別跑，我才不會讓你們為所欲為!!!
\n" + NOR);
          this_object()->set("FoundMystery",1);
        }  
        this_object()->move(room);
        command ("kill "+ob->query("id"));
      }
    }
  }
  :: heart_beat();
  set_heart_beat(1);  
}

