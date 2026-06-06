//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/21
//將add("kee")調整為receive_damage的攻擊參數並補上攻擊方之參數 by blazakira 2011/4/23

#include "/open/mogi/castle/npc/castle.h"
#include <ansi.h>
#include "killed.fun"       // 7.21.93 by Firedancer
#include "count-time.fun"   // 7.21.93 by Firedancer
inherit NPC;
   
void create()
{
  set("long","
    焚天魔王, 魔界之統治者, 他全身火焰繞身, 火舌隨著他的情緒不停的奔騰著。
仔細一看他竟可以御氣凌空, 內功\之深簡直不可思議。另外練就曠世絕學「極火功\」
, 極火掌一發動更是烈焰奔騰, 威不可擋。由極火功\所化成的「極火金身」護身
氣勁更能在四周形成堅硬火罩。
");
  set("gender","男性");
  set("nickname",HIR"赤獄混沅"NOR);
  set("title","魔界之王");
  set_name("焚天魔王",({"fire king","king"}));
  set("combat_exp",16000000);
  set("class","fighter");
//  set("attitude","aggressive");
  set("score",90000000);
  set("bellicosity",1000000);
  set("age",10000);
  set("max_force",70000);
//  set("no_poison",1);
  set("no_steal",1);
  set("force", 250000 ); 
  set("max_kee",70000);
  set("max_gin",70000);
  set("max_sen",70000);
  set("str", 35);
  set("cor", 35);
  set("cps", 35);
  set("int", 35);
  set("con", 35);
  set("kar", 35);
  set("force_factor",50);
  set_skill("dodge",200);
  set_skill("force",250);
  set("no_mount",1);
  set("no_plan_follow",1);
  set_skill("move",280);
  set_skill("parry",200);
  set_skill("mogi-steps",200);
  set_skill("firestrike",220);
  set_skill("unarmed",220);
  set_skill("literate",200);
  set_skill("fireforce",250);
  set_temp("apply/defense",60);
  set_temp("apply/armor",60);
  set_temp("apply/attack",30);
  set_temp("no_die_soon",1);
  map_skill("force","fireforce");
  map_skill("unarmed","firestrike");
  map_skill("dodge","mogi-steps");
  map_skill("move","mogi-steps");
  map_skill("parry","firestrike");
  set("functions/gold-fire/level",100);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  setup();
//  carry_object("open/mogi/castle/obj/fire-king-head");
  carry_object("/autoload/mogi/fire-armor")->wear();
  carry_object("/autoload/mogi/fire-cloud-boots")->wear();
  carry_object("/autoload/mogi/fire-belt")->wear();
  carry_object("/autoload/mogi/daemon-cloak")->wear();
  carry_object("/autoload/mogi/fire-dragon")->wield();
//  carry_object("/open/mogi/castle/obj/blood-water");   
  carry_object("/autoload/mogi/sspill")->set_amount(7);
  carry_object("/open/killer/headkill/obj/world_dag.c");
  add_money("gold",1000);
}

void init()
{
  ::init();
  add_action( "block_cmd", "" );
  add_action( "do_cmd", "cmd" );
  add_action( "do_exert", "exert" );
  if( this_player()->query("combat_exp") < 2500000 )
    add_action( "do_kill", "kill" );
}

// 擋 do, 以免 cmd 判斷失效 by ACKY
int block_cmd( string arg )
{
  if( (string)query_verb() == "do" ) {
    write( HIY"焚天魔王冷笑:「想耍下三爛的技倆?! 哼! 去死吧!」\n"NOR );
    if( is_fighting() )
      this_player()->start_busy(1);
    return 1;
  }
}

int do_cmd(string str){ //ok by chan
  string arg;
  object who=this_player();
  object ob,king;
  ob=this_object();
  king=present( "king",environment(ob) );
 
  if( !str )
    return 0;

  if(str=="askgod king" || str=="askgod fire king"){
    write(HIY"焚天魔王冷笑：「在本魔王面前求神問卜!?先問問我還差不多。」去死吧!!\n"NOR);
    command("perform fireforce.gold-fire");
    king->kill_ob(who);
    return 1;
  }
  if(str=="throw dark to king" || str=="throw dark to fire king"){
    write(HIY"焚天魔王冷笑：「敢對我用毒???」去死吧!!\n"NOR);
    command("perform fireforce.gold-fire");
    who->start_busy(1);
    king->kill_ob(who);
    return 1;
  }
  if(str=="throw rose to king" || str=="throw rose to fire king"){
    write(HIY"焚天魔王冷笑：「敢對我用毒???」去死吧!!\n"NOR);
    command("perform fireforce.gold-fire");
    who->start_busy(1);
    king->kill_ob(who);
    return 1;
  }
  if(str=="throw five to king" || str=="throw five to fire king"){
    write(HIY"焚天魔王冷笑：「敢對我用毒???」去死吧!!\n"NOR);
    command("perform fireforce.gold-fire");
    who->start_busy(1);
    king->kill_ob(who);
    return 1;
  }
  if(str=="vet king" || str=="vet fire king"){
    write(HIY"焚天魔王怒斥道：「死庸醫杵在這裡幹什麼？！不如我送你一程吧！！」\n"NOR);
    command("perform fireforce.gold-fire");
    king->kill_ob(who);
    return 1;
  }
  if(str=="bak king"){
    write(HIY"焚天魔王冷笑：想暗殺本魔王!!!也不打聽誰是暗殺之王呀!!!去死吧!!\n"NOR);
    command("perform fireforce.gold-fire");
    king->kill_ob(who);
    return 1;
  }

  if( sscanf( str, "%s %s", str, arg ) )
    if( str=="throw" ) {
      write( HIY"焚天魔王冷笑:「想幹什麼? 滾開!」\n"NOR );
      return 1;
    }
}

int do_kill( string str )
{
  object me = this_player();

  if( (str=="fire king"||str=="king") && me->query("combat_exp")<2500000 ) {
    write( HIY"焚天魔王冷冷地說:「你不夠資格殺我!」\n"NOR );
    return 1;
  }
  return 0;
}

void greeting( object me )
{
  write( HIY"焚天魔王發出懾人心神聲音:\n\t「來者何人～～」
\t「能來到這裡, 真不簡單! 江湖之上的人物, 算你一號!」
\t「不過若想找我比劃, 你還差得太遠!」
"NOR ); 
}

int accept_fight(object who)
{
  write( HIY"焚天魔王冷冷地說:「要命的話就快走吧!」\n"NOR );
  return 0;
}

int do_exert( string str )
{
  mixed all;
  int i;
  object me;
  me = this_player();
  all = all_inventory(environment(me));

  if( str=="roar" ) {
    say(HIC"$N氣凝丹田, 用力一吼企圖以內力震傷焚天魔王。\n", me );
    say(HIC"焚天魔王冷笑說『你這也叫吼? 讓你們見識一下真正的"HIR"天魔狂吼"HIC"吧!\n");
    say(HIR"\n焚天魔王大吼一聲, 剎那間天驚地搖, 魔界因此而震動! 周遭的生物剎那間非死即傷!\n");
    message_vision( HIR"結果所有人被這威力無比的天魔怒吼震傷, 哇一聲吐出一大口鮮血!\n"NOR, me );
    for( i=0 ; i<sizeof(all); i++ )
      if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
        all[i]->receive_damage( "kee", 600, this_object() );
        all[i]->delete_temp("hardshell");
        COMBAT_D->report_status( all[i], 1 );
      }
    return 1;
  }
  return 0;
}

int accept_kill( object who )
{
  write( HIY"焚天魔王從寶座上豁然站起!\n"NOR );
  command("say 鼠輩無禮! 嚐嚐我極火功\的厲害吧!");
  if( !is_fighting() )
    command("perform fireforce.gold-fire");
  return 1;
}

void heart_beat()
{
  object *all;
  object king;
  int i, j, tmp , count;

  king = this_object();
  if(!environment()) return ;
  all = all_inventory(environment(this_object()));
  count = random(100);
  j = random(3)+1;
//因為已調整為非天道吃白龍pill效果變差，故先解除這個心跳 by Alucard/2009/Sep
/*
// 加上機率清除白龍硬甲功能 by swy
// 加上新的射手功能影響 by swy
  if( 30 > random(100) ) {
    for(i=0;i<sizeof(all);i++) {
      if(!living(all[i])) continue;
      if(all[i]->query("id")=="fire king") continue;
      if(!all[i]->query_temp("hardshell")) continue;
      all[i]->delete_temp("hardshell");
      all[i]->clear_condition("white_pill");
      all[i]->set_temp("over/right",1);
      all[i]->set_temp("over/r-eyes",1);
      message_vision(HIG"\n焚天魔王發出一道強烈綠光$N身上的白龍能量消失了。\n"NOR,all[i]);
    }
  }
*/
//改變心跳出擊方式，fire king本身能力已經暴猛了，運氣不好心跳
//又一次全出，實在是太強了，就算再強的ppl也會一直被delay到死，
//連逃的機會也沒有，所以更動形式，改成全時段出，每一次心跳會隨
//機一種，若在數字邊緣則不出，若真的運氣不好一直出busy，那就運
//氣太差了。

  for( i=0 ; i<sizeof(all); i++ )
    if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" && !is_fighting(all[i]) )
      kill_ob(all[i]);

  if( count < 10 && is_fighting() ) { // 主打 busy
    message_vision( HIR"\n焚天魔王大喝一聲, 剎那間天驚地搖, 魔界因此而震動! 周遭的生物剎那間非死即碎!\n\n"NOR, king );
    message_vision( HIR"結果所有人被這威力無比的天魔怒吼震傷, 哇一聲吐出一大口鮮血!\n"NOR, king );
    for( i=0 ; i<sizeof(all); i++ )
      if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
        all[i]->receive_damage( "gin", 100, king );
        all[i]->start_busy(j);//變的隨機性質的，至少一回合，至多三回合。
        COMBAT_D->report_status( all[i], 1 );
      }
  }

  if( count > 10 && count < 25 && is_fighting() ) { // 主打 force
    message_vision( HIR"
	焚天魔王將全身業火暗運掌上, 掌上業火蘊藏著無限吸勁
	眨眼間, 焚天魔王叱喝迴盪"HIW"『魔道輪迴 業火橫行』"HIR"
	業火不斷向四周吸引氣勁!\n\n"NOR, king );
    message_vision( HIR"結果所有人八成內力全受業火吸引, 內勁狂洩!\n"NOR, king );
    for( i=0 ; i<sizeof(all) ; i++ )
      if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
        tmp = all[i]->query("force")/5*4;
        all[i]->add( "force", -tmp );
        king->add( "force", tmp );
      }   
  }

  if( count > 25 && count < 50 && is_fighting() ) { // 主打神
    message_vision( HIR"
	焚天魔王全身火焰繞身, 突然將周身業火暗運掌上,
	眨眼間, 焚天魔王叱喝迴盪"HIW"『魔道橫行 烈焰奔騰』"HIR"
	業火不斷向你襲來!\n\n"NOR, king );
    for( i=0 ; i<sizeof(all) ; i++ )
      if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" )
        all[i]->receive_wound( "sen", 100+random(100), king );
  }

  if( count > 50 && count < 80 && is_fighting() ) { // 主打mob
    message_vision( HIR"
	焚天魔王化身煉獄業火, 妖氣在一瞬間變成沸騰血紅魔風,
	凡被其吹拂之物盡揮成汽, 熔人口鼻令人窒息
	眨眼間, 焚天魔王叱喝迴盪"HIW"『赤獄混沅 魔道遮天』"HIR", 熔融魔氣挾著蝕骨
	焚燄之風瘋狂地侵襲著一切!\n\n"NOR, king );
    for( i=0 ; i<sizeof(all); i++ )
      if( living(all[i]) && !wizardp(all[i]) && !userp(all[i]) &&
        !all[i]->query("master") && all[i]->query("id")!="fire king" )
        all[i]->die();
  }

  if( count > 80 && is_fighting() ) { // 主打氣
    message_vision( HIR"
	焚天魔王化身煉獄業火, 妖氣在一瞬間變成沸騰血紅魔風,
	凡被其吹拂之物盡揮成汽, 熔人口鼻令人窒息
	眨眼間, 焚天魔王叱喝迴盪"HIW"『赤獄混沅 魔道遮天』"HIR", 熔融魔氣挾著蝕骨
	焚燄之風瘋狂地侵襲著一切!\n\n"NOR, king );
    message_vision( HIR"結果被熔融極火捲到, 哀嚎連連中渾身青煙直冒, 伴隨著陣陣焦肉味!\n"NOR, king );
    for( i=0 ; i<sizeof(all); i++ )
      if( living(all[i]) && !wizardp(all[i]) && all[i]->query("id")!="fire king" ) {
        all[i]->receive_wound( "kee", 1000, king );
        COMBAT_D->report_status( all[i], 1 );
      }
  } 

// 療傷太誇張了 每一次心跳有 50% 會療傷
// 真的打不死 再加上一層的判斷
// 0.5x0.7 = 0.35 差不多 35%    by swy
  if(random(100)>30) {
    if( random(100) < 50 && is_fighting() && king->query("kee") > 0 )
    {
      message_vision( HIG"\n焚天魔王身冒出熊熊火燄, 傷口漸漸的癒合了!\n"NOR, king );
      king->delete_busy();
      king->clear_condition();
      king->receive_curing("kee",5000);
      king->receive_heal("kee",5000);
      king->receive_curing("gin",5000);
      king->receive_heal("gin",5000);
      king->receive_curing("sen",5000);
      king->receive_heal("sen",5000);
    }
  }

// by babe 計算剛好, 不要調整
  if( !is_fighting() ) {
    if( query("force") < query("max_force") ) // 1 -> 5.035
      command( "ex 200" );
    if( query("eff_kee") < query("max_kee") ) // 35 -> 40
      command( "10 exert heal" );
    if( query("eff_gin") < query("max_gin") )
      king->receive_curing("gin",500);
    if( query("eff_sen") < query("max_sen") )
      king->receive_curing("gin",500);
    if( query("gin") < query("eff_gin") ) // 125
      command( "exert regenerate" );
    if( query("kee") < query("eff_kee") ) // 125 -> 300
      command( "4 exert recover" );
    if( query("sen") < query("eff_sen") ) // 125
      command( "exert refresh" );
    king->clear_condition();
  }

// enf 不減反增
  if( query("force_factor") < 40 )
  {
    king->set( "force_factor", 45 );
  }

  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  int i,j;
  object *enemy;
  
  object winner = query_temp("last_damage_from");
  object obh = new("open/mogi/castle/obj/fire-king-head");
  string name = winner->query("name");
  enemy = query_enemy();
  i=sizeof(enemy);
  
  tell_object(users(),HIW"
            
         焚天魔王仰天嘆道：『萬年以來我的驚世神功\無人能敵,
                             想不到今日敗於"+HIY+
                             (winner->query("family/family_name")?winner->query("family/family_name"):"")+
                             HIC+name+HIW"       
                             之手, 真是後生可畏～嘆啊～ 』

        "HIB"   魔界颳起狂風暴雨   一代魔界之王焚天魔王敗了!             
"NOR);
  if ( kill_jobs(5,winner,this_object(),"area/hole_stone") ) finish_time(winner,"area/hole_stone"); else start_time(winner,"area/hole_stone"); // 7.21.93 by Firedancer

  if(userp(winner)) log_file("mogi/KILL_FIRE_KING", sprintf("%s(%s) 打敗 焚天魔王 on %s\n",name,winner->query("id"), ctime(time()) ));

/*
//by ACKY
  if( random(100) < 10 )
    environment(this_object())->war_start();
*/
  if( winner->query("clan/id") )
    CLAN_D->add_clanset( winner->query("clan/id"), "develop" , 20 );

  tell_object(winner,"
\n焚天魔王說：好吧...既然你已經贏了我了，我就把風青雲
交給你了，反正這麼多年來他也不肯吐漏連陽七訣劍法的奧秘。
不過他被我用獨門手法點住了三元重穴，功\力已經被封
現在我傳你解穴手法(recover force)，你往北走可找到他。
\n");

  tell_object(winner,HIY"\n焚天魔王再用逼音成線的功\夫告訴你：
真是後生可畏...這樣我也沒必要隱藏我的絕學了，現在我就傳你
"HIR"極火金身心法"HIY"，極火真經就放在白虎室，慎習之！
\n"NOR);
  winner->set("quest/gold-fire",1);
  winner->set("quest/new_gold_fire",1);
  winner->set_temp("win_fireking",1);

  for(j=0;j<i;j++){
    if(enemy[j]->query("class")=="swordsman" && enemy[j]->query_temp("win_fireking")!=1)
    {
      enemy[j]->set_temp("win_fireking",1);
      tell_object(enemy[j],"焚天魔王說：好吧...既然你已經贏了我了，我就把風青雲
交給你了，反正這麼多年來他也不肯吐漏連陽七訣劍法的奧秘。
不過他被我用獨門手法點住了三元重穴，功\力已經被封
現在我傳你解穴手法(recover force)，你往北走可找到他。
\n");
    }
  }

//補充....................................
//武者解了話.會變成一代武尊....同時可以使用終極拳勢...................by chan
//補充lungshan可以解到kang-power...2002-12-25 --by kalin
  if(winner->query("class") == "fighter")
  {
    if((winner->query("combat_exp") > 5000000) && !winner->query("kang-power")&& winner->query("family/family_name")=="瀧山派")
    {
      winner->set("final/ko_king",1);
      winner->set("final/limit",1);
      winner->set("kang-power",1);
      tell_object(winner,HIR"你終於突破武學上極限!!悟出終極拳勢!!成為武尊!!\n"NOR);
      winner->set("title",HIY"玄天武尊"NOR);
      tell_object(winner,HIW"請打一下help 終極拳勢,可以得知更多的訊息....!!!\n"NOR);
      tell_object(winner,HIW"你在與焚天魔王戰鬥中不知不覺中領悟了焚天魔王極火功\的精髓，，
苦思了半餉之後突然頓悟到將極火功\融入浩日心法裡，遂大聲狂歡道
"+HIG+"★★"HIW"--"HIR"烈燄浩氣"HIW"--"HIG"★★\n"NOR);
    }
    if((winner->query("combat_exp") > 5000000) && !(winner->query("final/ko_king")))
    {
      winner->set("final/ko_king",1);
      winner->set("final/limit",1);
      tell_object(winner,HIR"你終於突破武學上極限!!悟出終極拳勢!!成為武尊!!\n"NOR);
      winner->set("title",HIY"玄天武尊"NOR);
      tell_object(winner,HIW"請打一下help 終極拳勢,可以得知更多的訊息....!!!\n"NOR);
    }
  }

//補充刀客解了能有制刀術 by swy
  if(winner->query("class") == "blademan")
    if(winner->query("combat_exp")>5000000&&!winner->query("mk-blade")&&userp(winner))
    {
      winner->set("mk-blade",1);
      tell_object(winner,HIY"\n焚天魔王再用逼音成線的功\夫告訴你：
真是後生可畏...這樣我也沒必要隱藏我的絕學了，現在我就傳你
"HIR"邪靈制刀術"HIY"，慎習之！\n"NOR);
      if(winner->query("gender")=="男性") { winner->set("title",HIW"漩羽"HIY"刀皇"NOR); }
      else { winner->set("title",HIB"刀魂"HIC"幽姬"NOR); }
      write("請打一下 help 邪靈制刀術，能知道更多訊息。\n");
    }

//Bellow Add By AceLan.......
//2002-12-25 add--by kalin
  if( winner->query("family/family_name")=="儒門" && winner->query("combat_exp")>3000000 && !winner->query("plan-quest/ko-fire-king"))
  {
    tell_object(winner,HIW"你憑藉著高深的心法在不知不覺中領悟了焚天魔王極火功\的精髓，
苦思了半餉之後突然頓悟到將極火功\融入孔明兵法之道，遂大聲狂歡道
"+HIR+"==========『極火一出，萬物具焚』==========\n"
NOR);
    winner->set("plan-quest/ko-fire-king",1);
    winner->set("title",HBRED"ω"HIR"赤火"HIW"。"HIC"傲世"HIY"儒俠"HIW"ω"NOR);
  }

  if( random(3) == 1 )
  {
    message_vision(HIW"$N"HIW"順利的擊殺了$n"HIW"，並將$n"HIW"的賞金頭給割了下來!!\n"NOR,winner,this_object());
    obh->move(winner);
  }else{
    message_vision(HIR"$N"HIR"一招勁力太強橫，竟然把$n"HIR"給轟的支離破碎了，連賞金的頭也給轟爛了!!\n"NOR,winner,this_object());
  }

//加入銀針門神農quest所需 temp by blazakira
  if (winner && winner->query("family/family_name")=="銀針門" && random(100) > 30 && query_temp("record_damage/"+winner->query("id")) > query("max_kee")/5) {
    winner->set_temp("spiritup",query("id"));
  }

  :: die();
}                    

void record_damage(int damage, object who)
{
  if(!who) return ;
  if(who && !userp(who)) return ;
  add_temp("record_damage/"+who->query("id") , damage);
}
varargs int receive_damage(string type, int damage, object who)
{
  ::receive_damage(type,damage,who);
  who = query_temp("last_damage_from");
  record_damage(damage,who);
}
varargs int receive_wound(string type, int damage, object who)
{
  ::receive_wound(type,damage,who);
  who = query_temp("last_damage_from");

  record_damage(damage,who);

}
