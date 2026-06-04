#include <ansi.h>
#include <combat.h>
inherit NPC;
//inherit SSERVER;

void hawk1(object me, object victim, object  weapon, int damage);
void hawk2(object me, object victim, object  weapon, int damage);
void hawk3(object me, object victim, object  weapon, int damage);
void hawk4(object me, object victim, object  weapon, int damage);
void hawk5(object me, object victim, object  weapon, int damage);
void sp1(object me, object victim, object  weapon, int damage);
void sp2(object me, object victim, object  weapon, int damage);

mapping *action = ({
([ "action" : "$N" + HIC + "使出" + HIY + "『" + HIB + "鷹魂七變" + HIY + "』" + HIG + "--" + HIR + "鷹嘯天際，" + HIC + "瞬間四周魔音產生，刺激著$n" + HIC + "的腦部，令人神智不清。" + NOR,
             "dodge"      :  -25,
             "parry"      :  -25,
             "damage"     :  200,
             "post_action":               (: hawk1 :),
             "damage_type":  "神智不清",
]),

([ "action" : "$N" + HIM + "使出" + HIY + "『" + HIB + "鷹魂七變" + HIY + "』" + HIG + "--" + HIY + "暗潮洶湧" + HIM + "，由鷹翅所捲起的強烈氣流襲捲而出，$n" + HIM + "被捲入空中，重摔於地。" + NOR,
             "dodge"      :  -15,
             "parry"      :  -15,
             "damage"     :  180,
             "post_action":               (: hawk2 :),
             "damage_type":  "摔傷",
]),

([ "action" : "$N" + HIB + "使出" + HIY + "『" + HIB + "鷹魂七變" + HIY + "』" + HIG + "--" + HIG + "斗換星移" + HIB + "，瞬間黑雲密佈，大地黑暗，靈鷹趁機朝$n" + HIB + "發動凌厲攻勢。" + NOR,
             "dodge"      :  -30,
             "parry"      :  -30,
             "damage"     :  100,
             "damage_type":  "抓傷",
]),

([ "action" : "$N" + HIC + "使出" + HIY + "『" + HIB + "鷹魂七變" + HIY + "』" + HIG + "--" + HIM + "月舞霓裳" + HIC + "，藉月光濛濛之際飛舞天際，令$n" + HIC + "看的如癡如醉，無法招架。" + NOR,
             "dodge"      :  -15,
             "parry"      :  -15,
             "damage"     :  180,
             "post_action":               (: hawk3 :),
             "damage_type":  "抓傷",
]),

([ "action" : "$N" + HIB + "使出" + HIY + "『" + HIB + "鷹魂七變" + HIY + "』" + HIG + "--" + HIR + "燄陽九天" + HIB + "，只見烈日高照，靈鷹長嘯一聲俯衝而下迅速攻擊$n。" + NOR,
             "dodge"      :  -30,
             "parry"      :  -20,
             "damage"     :  100,
             "damage_type":  "抓傷",
]),

([ "action" : "$N" + HIG + "使出" + HIY + "『" + HIB + "鷹魂七變" + HIY + "』" + HIG + "--" + HIM + "昏天暗地" + HIG + "，滿天烏雲籠罩不見光明，靈鷹翱翔天際，趁著黑暗之中奇襲$n。" + NOR,
             "dodge"      :  -20,
             "parry"      :  -25,
             "damage"     :  200,
             "post_action":               (: hawk4 :),
             "damage_type":  "抓傷",
]),

([ "action" : "$N" + HIC + "使出" + HIY + "『" + HIB + "鷹魂七變" + HIY + "』" + HIG + "--" + HIR + "天靈" + HIG + "地氣" + HIC + "，只見靈鷹吸收天地靈氣身形不斷膨脹，順勢俯衝而下挾帶一股強大氣流攻擊$n。" + NOR,
             "dodge"      :  -30,
             "parry"      :  -30,
             "damage"     :  250,
             "post_action":               (: hawk5 :),
             "damage_type":  "靈氣血傷",
]),

([ "action" : HIY + "靈鷹紫翎化身五彩金翎，身上羽翼閃閃發光，瞬息間從天而降迅速張爪攻擊$n。" + NOR,
             "dodge"      :  -25,
             "parry"      :  -30,
             "damage"     :  220,
             "damage_type":  "抓傷",
]),

([ "action" : "$N" + HIY + "以天生神力加上$N" + HIY + "奇妙咒法，形成一道火球燃燒著目瞪口呆的$n。" + NOR,
             "dodge"      :  -30,
             "parry"      :  -30,
             "damage"     :  250,
             "post_action":               (: sp1 :),
             "damage_type":  "燒傷",
]),

([ "action" : HIM + "靈鷹紫翎口吐煙霧，在若隱若現之間鷹眼大放異彩，靈鷹本身靈氣化成一道強大的氣流無情的攻擊$n。" + NOR,
             "dodge"      :  -30,
             "parry"      :  -30,
             "damage"     :  250,
             "post_action":               (: sp2 :),
             "damage_type":  "割傷",
]),


});

object room2;
void create()
{
        set_name(HIM + "紫翎" + NOR ,({"manes hawk", "hawk"}) );
        set("race", "野獸");
        set("nickname", HIG + "靈鷹" + NOR);
        set("age",534);
        set("long","生長於崑崙山頂，集天地靈氣為一身的稀世珍禽，背負著守護天道的重要使命\n百年前天道始祖命名為天道聖獸，據說其通靈達性，極為忠心。\n");
        set("str", 50);
        set("cor", 50);
        set("int", 50);
        set("con", 50);
        set("cps", 50);
        set("spi", 50);
        set("per", 50);
        set("kar", 50);
        set("kee", 50000);
        set("gin", 20000);
        set("sen", 20000);
        set("atman",20000);
        set("mana",20000);
        set("force", 100000);
        set("max_kee", 50000);
        set("max_atman",20000);
        set("max_mana",20000);
        set("max_gin", 20000);
        set("max_sen", 20000);
        set("max_force", 100000);
        set("score",100000);
        set("bellicosity", 5000);
        set_skill("move",120);
        set_skill("dodge",120);
        set_skill("parry",120);
        set("force_factor",15);
        set_skill("unarmed",120);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs",({"bite","claw"}));
        setup();

        set("default_actions", (: call_other, __FILE__,"query_action" :));
        reset_action();
}

mapping query_action(object me)
{
    return action[random(sizeof(action))];
}

void hawk1(object me, object victim, object  weapon, int damage)
{

     message_vision(sprintf(HIB + "\n群山萬谷受到" + HIG + "$N" + HIB + "的嘯聲所引，瞬間迴聲四起形成數道音波轟隆數聲擊向$n。\n" + NOR),me,victim);
               victim->receive_damage("gin", victim->query("max_gin",1)/10);
               victim->receive_damage("sen", victim->query("max_sen",1)/10);
               victim->start_busy(1);
               COMBAT_D->report_status(victim, 1);
}

void hawk2(object me, object victim, object  weapon, int damage)
{

     message_vision(sprintf(HIC + "\n四周氣流瞬間如潮水動盪不停，$n" + HIC + "受潮流影響漸漸被捲入旋渦中動彈不得。\n" + NOR),me,victim);
               victim->receive_damage("kee", victim->query("combat_exp",1)/15000);
               COMBAT_D->report_status(victim, 1);
}

void hawk3(object me, object victim, object  weapon, int damage)
{

     message_vision(sprintf(HIY + "\n\n-----  " + HIM + "舞  " + HIB + "※  " + HIC + "極 " + HIW + "～ " + HIR + "殺  " + HIY + "-----\n\n" + HIG + "天空飄來陣陣音響如夢似幻，迷濛的月光下顯現數道女子苗條身影翩翩起舞，四周瀰漫著一股\n" + HIG + "寧靜的氣息，令人陶醉其中殊不知殺機逼進，只見女子瞬間化為鷹羽如流星般的飛向$n。\n" + NOR),me,victim);
               victim->receive_damage("kee", victim->query("max_kee",1)/10);
               victim->add("force", -(victim->query("max_force",1)/10));
               COMBAT_D->report_status(victim, 1);
}

void hawk4(object me, object victim, object  weapon, int damage)
{
    int hawkup;
    hawkup = victim->query("combat_exp",1)/10000 + victim->query("max_force",1)/15 + victim->query("max_kee",1)/15;

     message_vision(sprintf(HIY + "\n靈鷹紫翎揮動雙翅捲起一陣狂風吹沙，瞬間塵沙飛揚，大地猶如土龍翻身撼動不停。\n" + NOR),me,victim);
               victim->receive_damage("kee", hawkup,me);
               COMBAT_D->report_status(victim, 1);
}

void hawk5(object me, object victim, object  weapon, int damage)
{
  int i;
  message_vision(HIM + "\n靈鷹" + HIG + "高聲長嘯︰可恨的人類們，給我下地獄去吧！\n                                             " + HIY + "天雷啊！聽我號令讓那大地毀滅吧！\n                                             " + HIR + "神火啊！助吾神威將那萬物焚燒吧！\n\n" + HIM + "瞬間大地為之憾動，天空降下無情天雷，地底湧起無數烈火，同時擊中$n。\n\n" + NOR,me,victim);
  for(i=1;i<=6;i++)
  {
    switch(random(i)+2)
    {
     case 1:
message_vision(sprintf(HIG + "      ＿ˍ▁▂▃▄▅▆▇█ $N" + HIY + "仰天長嘯，天雷啊！毀天滅地助我神威吧。" + HIG + "█▇▆▅▄▃▂▁ˍ＿\n" + NOR),me,victim);
     break;
     case 2:
message_vision(sprintf(HIG + "      ＿ˍ▁▂▃▄▅▆▇█ $N" + HIR + "仰天長嘯，地火啊！焚燒大地顯我神威吧。" + HIG + "█▇▆▅▄▃▂▁ˍ＿\n" + NOR),me,victim);
     break;
     case 3:
message_vision(sprintf(HIG + "      ＿ˍ▁▂▃▄▅▆▇█ $N" + HIY + "仰天長嘯，怒雷啊！翻雲覆雨助我神威吧。" + HIG + "█▇▆▅▄▃▂▁ˍ＿\n" + NOR),me,victim);
     break;
     case 4:
message_vision(sprintf(HIG + "      ＿ˍ▁▂▃▄▅▆▇█ $N" + HIR + "仰天長嘯，魔火啊！焚化萬物顯我神威吧。" + HIG + "█▇▆▅▄▃▂▁ˍ＿\n" + NOR),me,victim);
     break;
     case 5:
message_vision(sprintf(HIG + "      ＿ˍ▁▂▃▄▅▆▇█ $N" + HIY + "仰天長嘯，狂雷啊！怒嘯天地助我神威吧。" + HIG + "█▇▆▅▄▃▂▁ˍ＿\n" + NOR),me,victim);
     break;
     case 6:
message_vision(sprintf(HIG + "      ＿ˍ▁▂▃▄▅▆▇█ $N" + HIR + "仰天長嘯，神火啊！照耀大地顯我神威吧。" + HIG + "█▇▆▅▄▃▂▁ˍ＿\n" + NOR),me,victim);
     break;
     }
  if( 80 >random(100) )
     {
          message_vision(sprintf(HIB + "$n身受雷火兩極之傷，生命力已經一點一滴的慢慢消逝了！\n" + NOR),me,victim);
          victim->receive_wound("kee",800,me);
          if(i != 7)
          COMBAT_D->report_status(victim,1);
          else if( damage <=0 )
          COMBAT_D->report_status(victim,1);
     }
     else
     {
           message_vision(sprintf(WHT + "$n在千鈞一髮之際躲過了雷火兩極的傷害！\n" + NOR),me,victim);
     }
   }
  }

void init()
{
       
      set_heart_beat(1);
}
void sp1(object me, object victim, object  weapon, int damage)
{

     message_vision(sprintf(HIY + "\n\n$N緩緩唸著︰\n                    " + HIB + "┌" + HIR + "臨    " + HIW + "兵    " + HIG + "鬥    " + HIY + "者    " + HIC + "皆    " + HIG + "陣    " + HIR + "列    " + HIB + "在    " + HIM + "前" + HIB + "┐\n                    " + HIB + "│   " + HIW + "～    ～    ～    ～    ～    ～    ～    ～   " + HIB + "│\n                    " + HIB + "└────────" + HIM + "◆" + HIC + "誅          " + HIR + "邪" + HIM + "◆" + HIB + "────────┘\n\n" + HIR + "沉寂大地的遠古神龍受到召喚呼嘯而出，與靈鷹翱翔九天狂吼長嘯，兩道靈光瞬間穿透$n的身體。\n\n" + NOR),me,victim);
               victim->receive_damage("kee", 800 );
               COMBAT_D->report_status(victim, 1);
}

void sp2(object me, object victim, object  weapon, int damage)
{

     message_vision(sprintf(HIM + "\n          ●  ●  ●  " + HIC + "雪  花  紛  紛  " + HIW + "～  " + HIG + "天  靈  " + HIB + "地  氣  " + HIM + "●  ●  ●\n" + NOR),me,victim);
               victim->receive_damage("kee", 300 );
               victim->receive_damage("gin", 300 );
               victim->receive_damage("sen", 300 );
               victim->add("force", -500 );
               victim->start_busy(1);
               COMBAT_D->report_status(victim, 1);
}

void invocation(object who,object room)
{
        int i;
        object *enemy;
		room2=room;

        message("vision",
          NOR+name() + HIY + "大聲的咆哮著:\n" + HIR + "                   愚蠢的人啊！竟敢傷害吾守護的天道門徒！！\n" + HIR + "               　　如今我靈鷹守護在此,就讓你嘗嘗死亡的滋味.....\n" + NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
		set_leader(who);
        command("defend "+who->query("id"));
        who->set_temp("have_hawk",1);
        
}

void heart_beat()
{
 object env,me,*enemy,target,ob,who;
 int kee,i;

   i=random(sizeof(enemy));
   ob=this_object()->query_enemy();
 me = this_object();
 who = query_leader();
 env = environment(me);
        if(!who){
        call_out("leave",0);
        return ;
        }
		if (!me->is_fighting() ) {
	     call_out("leave",0);
	     return;
	    }
	    if(environment(me)!=environment(who)||!who->is_fighting()) {
             call_out("leave",0);
             return;
         }
/*        if(!target->is_fighting())
        {
        call_out("leave",0);
        return;
        } */
 if( random(100) < 50)
 {
    enemy=me->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
    kee = random(target->query("kee")*0.4);
    if( env == environment(target) )
    {
message_vision(HIY + "四周捲起一陣氣流，將$N捲入天空重摔於地。\n"+NOR,target);
      target->receive_damage("kee", kee);
      target->receive_wound("kee", random(kee) );
      target->receive_wound("sen", random(5) );
      target->receive_wound("gin", random(5) );
      COMBAT_D->report_status(target,0);
    }
	}
        
     
 

 if((me->query("kee")<me->query("max_kee")*0.1) && (random(100) < 5) )
 {
    tell_room(environment(), HIG + "靈鷹" + HIC + "眼見主人的生命如" + NOR+RED + "風中殘蠋" + HIC + "，仰天泣鳴不停，其聲" + HIY + "驚天地" + HIC + "，" + HIG + "泣鬼神" + HIC + "，瞬間" + HIM + "天地靈氣" + HIC + "齊聚，星象異變\n\n                    " + HIW + "～　" + HIR + "鷹　　　魂　　　" + HIY + "泣　　　天　　　地　" + HIW + "～" + NOR + "\n\n" + HIM + "靈鷹吸收日月精華，身影不斷的漲大，瞬息間奔向敵人纏繞其身，悲鳴一聲，靈鷹自爆產生一股\n巨大的毀滅力，令萬物毀滅，天地重生，周遭人物盡數毀滅，其主人受鷹魂所佑順利逃過此一劫數。\n"+NOR);
   ob->die();
 }

   ::heart_beat();

}

void leave()
{
        object who = query_leader();

        message_vision ("$N" + HIY + "說道:吾之責任盡了，主人多加珍重！\n" +
        HIC + "四週漸漸泛起一陣雲霧，$N" + HIC + "長嘯數聲朝天飛馳而去。\n" NOR, this_object());
        if (who)
        who->set_temp("have_hawk",0);
        destruct(this_object());
}

void unconcious ()
{
        object who = query_leader();
        if (who)
        who->set_temp("have_hawk",0);
  message_vision (HIR + "$N慘叫一聲啊！天靈地氣化為烏有，消失的無影無蹤。\n", this_object ());
  destruct (this_object());
}

void die()
{
        object who = query_leader();
        if (who)
        who->set_temp("have_hawk",0);
        message_vision ("$N" + HIR + "慘叫一聲  啊！  恕我無法再保護主人了。\n" + NOR, this_object());
        destruct (this_object());

        ::die();
}
