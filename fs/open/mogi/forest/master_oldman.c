#include <ansi.h>
#include <combat.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
string ask_ball()
{
 if(!this_player()->query_temp("swordtime"))
 {
  return ("對不起﹐你問的事我實在沒有印象。");
  }
 else
  {
  if (this_player()->query("class")=="blademan"||this_player()->query_temp("swordquest/findball")==1)
    {
    this_player()->set_temp("swordquest/findball",2);
    return ("卻有所聞﹐但此物早已消失人間﹐你如真要查詢的話﹐金刀門或許\是不錯的選擇。\n");
   }
else return ("對不起﹐你問的事我實在沒有印象。");
 }
}
void create()
{
        set_name("魔刀莫測",({"oldman"}));
set("long", "一個看起來全身髒盻盻的老人，腳上還有一個腳銬，看起來像是被關在這裡的。\n");
        set("gender", "男性" );
        create_family("魔刀莫測",1,"開創始祖");
        set("family/family_name","魔刀莫測");
        set("have_book",1);
        set("title","魔仙雪～刀劍蒼");
        set("age",70);
        set("env/魔性六斬","YES");
      set("mpower",2);
        set("str",45);
        set("class","blademan");
        set("guild_class","blademan");
        set("cor", 30);
        set("cps", 30);
        set("int", 25);
        set("max_gin",1000);
        set("max_sen",1000);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",30);
        set("kee",5000);
        set("score",100000);
        set("max_kee",5000);
        set("bellicosity",3000);
        set_skill("cure",60);
        set_skill("riding",100);
        set_skill("force", 100);
        set_skill("blade",120);
        set_skill("dodge", 70);
        set_skill("move", 70);
        set_skill("powerforce", 100);
        set_skill("dragon-blade", 120);
        set_skill("parry", 100);
        map_skill("parry","dragon-blade");
        map_skill("blade","dragon-blade");
        map_skill("force","powerforce");
        set("combat_exp",1500000);
        set("chat_chance_combat",50);
        set_temp("apply/armor",100);
        set("chat_msg_combat",({
        (: perform_action, "blade.swy" :),
      }));
        set("inquiry", ([
"腳銬":"這個腳銬是用千年寒石打造的，一般兵器是砍不斷的。\n",
"千年寒石":"這是經過千年孕育而成的堅硬石塊，除非有神兵利器，不然無法砍斷。\n",
"神兵利器":"聽說人間至寶「金鱗蟒邪」配上「天邪石」可以毀滅千年寒石。\n",
"金鱗蟒邪":"聽說金鱗蟒邪好像落在茅山派手上。\n",
"天邪石":"天邪石在獨孤愁傳人的手裡。\n",
"失傳奧義":"那招是狂龍刀法最後一招，可惜刀譜已被莫無樂給奪走了，
　　　　　　如果你能奪回來，我就傳你那失傳奧義。",
"莫無樂":"是我最喜愛的徒弟，可惜心術不正想篡我門，又奪取我刀法最後一式，
　　　　　最後被我兒子打敗，就不知去向了，不過．．．．",
"不過":"不過，聽說他去投靠世仇雪蒼派去了，目前佔據魔龍塔當作要塞。",
"魔龍塔":"在魔刀門內，自己去找吧！",
"鎮教之寶":"哈哈......那是我當年威震武林時所用的配刀。\n",
"配刀":"那把刀是我剛闖蕩江湖，而未創立魔刀時巧遇貴人，但那時他已經奄奄一息，從他口中得知刀塚位置之後，也知道最好的刀名叫『妖刀村雨』。\n",
"妖刀村雨":"在二十年前與獨孤愁在雪蒼山一戰後，那把刀就受損了，此刀以被葬回刀塚。\n",
"刀塚":"嗯...恐怕你不夠資格到那吧。\n",
"夜千鳥晶珠" : (:ask_ball:),
"資格":"只要你能接住我七招，我就把刀塚位置跟你說(test 資格)。\n",
"莫雲":"不過他仙遊已久，不過聽說有傳人，傳人好像一直待在西域吧！\n",
        ]));
        add_temp("apply/dodge",30);
        setup();
        carry_object("/daemon/class/blademan/obj/iceblade")->wield();
}
void attempt_apprentice(object ob)
{
if(this_player()->query_skill("dragon-blade",1)<105)
{
command("say 狂龍刀法都學不好了！還想拜我！滾！你給我滾開！\n");
return ;
}
if(this_player()->query("have_book")!=1)
{
command("say 雖然你狂龍刀法已到達一定水準！但是尚缺上乘奧義！");
command("say 可惜！我畢生所鑽研的刀譜！卻被莫無樂給盜走了！");
command("say 如果你能追回的話！我就收你為徒！更傳你魔刀最後失傳奧義！");
return ;
}
        command("smile");
        command("say 嗯，果然青出於藍，從今後老夫親自傳授於你。");
        command("say 但是魔刀武學不能外傳，切記，切記。");
        ob->delete("family");
        command("recruit "+this_player()->query("id"));
if(this_player()->query("m_blade")==1) {
this_player()->set("title","魔刀『三斬歸元』傳人"); } else {
        this_player()->set("title",HIC + "魔刀絕世傳人" + NOR);
}
        this_player()->set("no_recruit", 1);
        message("system",HIB + "魔刀莫測縱聲狂笑:
\n哈哈哈哈～～魔刀一出～～血流成河～～無所匹敵。\n" + NOR,users());
        return ;
        }
int accept_object(object who,object ob)
{
string ob_id;
ob_id=ob->query("id");
if(who->query("quests/blade_out")==0||who->query_skill("dragon-blade",1)>=105)
{
if(who->query("evil-mblade")==1) {
if(ob_id=="bad-evil-mblade") {
command("say 太好了，這正是我之前的配刀！");
command("say 可惜刀身以毀，當今世上只有『莫雲』會修！");
command("say 你去找他吧！");
command("give "+this_player()->query("id")+" bad-evil-mblade");
}}
if(ob->query("id")=="dragon-blade book"&&who->query("family/family_name")=="魔刀門")
{
if(who->query("have_book")==0)
{
destruct(ob);
command("say 你竟能將刀譜追回，果然是個可造之才！");
command("say 好，我就將狂龍刀法『失傳奧義』傳給你！\n");
who->set("have_book",1);
}
}
if(ob_id=="stone"&&who->query_temp("give_1")==0)
{
destruct(ob);
command("say 我沒看錯吧，你竟然能將天邪石拿到手！");
this_player()->set_temp("give_1",1);
}
if(ob_id=="snake sword"&&who->query_temp("give_2")==0)
{
destruct(ob);
command("say 太好了，這正是我需要的東西！");
this_player()->set_temp("give_2",1);
}
if(who->query_temp("give_1")==1&&who->query_temp("give_2")==1&&who->query("quest/blade_out/get_force")==0)
{
    command("say 太好了！");
    message_vision(
             HIY
"$n將天邪石的神力注入金鱗蟒邪之中，然後運勁一砍，將腳銬砍斷。\n" + NOR,this_player(),this_object());
    CHANNEL_D->do_channel(this_object(),"mud",HIR
"遠處傳來魔刀莫測的大喝:\n我自由了！哈哈哈哈！\n獨孤愁！你這個老賊等著吧！我要一雪這十幾年禁錮之恨！\n" + NOR);
           command("say 感謝你釋放了我，我這就去宰了獨孤老賊。");
           command("say 不過看在你曾幫我，好吧，我將部分內力傳給你。");
           this_player()->add("max_force",100);
           this_player()->add("force",100);
           who->set("quests/blade_out",1);
           who->set("quest/blade_out/get_force",1);
           return 1;
}
}
}
void init()
{
   add_action("do_test","test");
}
int do_test(string str)
{
        int i;
        object ob=this_object();
        object me=this_player();
if(me->query_temp("sublade")==1)
return notify_fail("刀塚的路就在薜荔蘿林內！\n");
if(me->query("m_blade")!=1)
return notify_fail("依你目前能力沒資格接我七招，等你有三斬再來吧！\n");
    if(str=="資格")
        {
          command("say 好! 待老夫來試試你! 小心了");
     for(i=0;i<7;i++)
COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), TYPE_QUICK);

          if( me->query("kee") > 500 )
          {
 command("say 果然真有本事！如你能幫我把配刀取回，我就傳你此刀！");
     command("say 刀塚的路就在薜荔蘿林內！自行找吧。");
            me->set_temp("sublade",1);
          }
          else
          {
            command("say 你再加強自己本事吧！");
          }}
        else {
          write("接受什麼?!\n");
        }
return 1;
}
void heart_beat()
{
object me,room,*target;
int i,j;
me=this_object();
if( me->is_fighting() && random(100) > 60 && !me->query_temp("fast-dest") ) 
{
message_vision(HIC + "\n魔刀莫測吃起藥丸補充血氣。\n" + NOR,me);
me->receive_curing("kee",1500);
me->receive_heal("kee",1500);
me->delete_busy();
me->clear_condition();
   }
  ::heart_beat();
  }
void die()
{
	object winner = query_temp("last_damage_from");
	int j;
	if(!winner)
	{
	::die();
	return ;
	}
   if (winner && userp(winner))  {
tell_object(users(),HIR + "\n\n魔刀莫測仰天怒吼：\n\n\t想當年老夫刀法名震武林卻敗於"+winner->name()+HIR"手上！
\n\t沒想到竟然有比獨孤老賊更利害得人物！罷了罷了！\n\n" + NOR);
   }
        :: die();
}

