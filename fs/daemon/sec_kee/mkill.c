// 1998/9/29  wataru 改編自雷虎之氣
//由於這是殺手的第三段轉職才可以學到的氣
//所以基本上，會比較強大，可以算是進階的技巧，請QC的大神多加斟酌
//學到這一個氣的玩家EXP大約必須在 80萬以上，並不是每個人都可以學到的
//主要是利用殺氣與靈氣，配合bellup使用出來的一種殺意魔氣
//因為花費的是殺氣，（殺氣並不會自動回復），所以威力自然也強大
//效果主要是以強大的殺意去消滅對手的精，神，並且使對手動作遲緩
//但因為規定只可以busy 1 ，所以，牽制的回數會增加，希望qcer可以通融
//牽制的回數會與所花費的殺氣有關，所可花的殺氣與玩家的magic lv有關
//殺手的master yar magic lv 是20，所以請qcer列入考慮
//1998/12/11 再次修正，修正有關因為magic lv 不易控制
//1999/4/29   再次修正，修正有關沒有心跳的問題，並改善訊息的輸出
//1999/5/19   再次修正，修正有關吃下絕世丹藥後的威力增幅
//2000/1/24   再次修正﹐為適應目前fs的強度﹐修正殺意魔氣
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
int kee_out(object me,object target)
{
    int mkilluse,cor,maxskee;
    int magic_lv,makee_lv;
    int sha_lv,rain_lv;
    int mix_power;
    int ext_power=0;

    if (me->query("quest/worldpill") == 1)
        ext_power=120;  //吃下絕世丹藥後的威力增幅
    cor=me->query_cor();
    maxskee   =me->query("max_s_kee");
    magic_lv  =me->query_skill("magic",1);
    sha_lv    =me->query_skill("shadow-kill",1)*2;         //max lv 90
    rain_lv   =me->query_skill("rain-throwing",1);       //max lv 100
    makee_lv  =me->query("/functions/manakee/level")*2;    //max lv 150
    mix_power=sha_lv+rain_lv+makee_lv+ext_power;

    //如果magic lv 80的話，最多可以使用10單位的殺氣
    //加1是避免出現零次的機會
    //用於控制持續回數
    if (magic_lv > 80)
        magic_lv=80;
    mkilluse=random(magic_lv /8)+1;

        if(me->query("class") != "killer")
        {
         tell_object(me,"自從你離開殺手後，就發現心中的魔氣逐漸消失...\n");
                return 1;
        }
        if(me->query("quest/head-kill") != 1)
        {
                tell_object(me,"ㄟ......你想用什麼氣呀？要用？自己放屁會快一點\n");
                return 1;
        }
        if(me->query("s_kee")< 20)
        {
                tell_object(me,"你的殺意魔氣修練不夠精深，多練一下再用吧！\n");
                return 1;
        }

      if( !target   ||   !target->is_character()   ||      !me->is_fighting(target) )
                return notify_fail("『殺意魔氣』只能對戰鬥中的對手使用。\n");

        if(target->query_temp("mkill")==1)
        {
                tell_object(me,"敵人目前被殺意魔氣糾纏著，先攻擊等會再放殺氣\n");
                return 1;
        }
        if (me->query("bellup") != 1)
        {
                tell_object(me, "感覺起來你還不夠想殺人嘛！怎麼不用殺意升這一招\n");
                return 1;
        }
        if (me->query("bellicosity") < 500)
        {
                tell_object(me, "殺氣不夠啦！那要怎麼用殺氣來威嚇對手呢？\n");
                return 1;
        }
        if (me->query_skill("magic") < 10)
        {
                tell_object(me, "連點法術也不學，那怎麼會有足夠的靈力來控制殺氣\n");
                return 1;
        }
        if (me->query("atman") < 30)
        {
                tell_object(me, "靈力不夠啦，這樣你會自滅哦！？\n");
                return 1;
        }
    //以下是花費
    me->add("bellicosity",-(mkilluse*5));  //因為使用殺氣恫嚇對方
    me->add("atman",-30);                      //使用靈力來結合殺氣與靈氣
    me->add("s_kee",-20);                      //所需花去的靈氣量


//持續回數最高mkilluse可能到10，威力以最大靈氣量來分等級
//這根本是變態，把靈氣練到lv 250以上，由lv200->lv 250最少需要230000的atman值
//所以給予一擊必殺的威力，但把靈氣等級降30，使玩家不能練比lv 250更高
 if (maxskee > 250)
 {
   me->add("max_s_kee",-30);                   //所需花去的靈氣等級
   message_vision(HIM + "  殺      意      魔      氣\n\n" + NOR,me);
   message_vision(HIM + "超頂級威力        **紫**級**魔**氣**      \n\n" + NOR,me);
   message_vision(HIM + "超精純的殺意魔氣化成真元由$N體內射出，這是具有無比威力的魔氣\n" + NOR,me);
   message_vision(HIM + "$N的魔氣真元在瞬間射入$n體內，無比的威力在其體內爆發！\n" + NOR,me,target);
   target->start_busy(2);
   target->receive_damage("gin",random(mix_power*2));
   target->receive_damage("sen",random(cor*40));   //膽識30*40=1200 一般是一擊必殺，重要NPC不會有問題
   //且殺手的膽識大約在20-25之間, 20*20＝400，也就是只要膽識低一些，威力就降很多
 }
 else if (maxskee > 200)
 {
   message_vision(HIM + "  殺      意      魔      氣\n\n" + NOR,me);
   message_vision(HIG + "頂級威力          *綠*級*魔*氣*   \n\n" + NOR,me);
   message_vision(HIG + "$N由自身爆出強烈的殺氣，這是一種帶有魔力的殺氣\n" + NOR,me);
   message_vision(HIG + "$N地獄般的魔氣瞬間籠罩$n，令其感到劇烈的恐懼感！\n" + NOR,me,target);
   target->start_busy(2);
   target->receive_damage("gin",random(mix_power));
   target->receive_damage("sen",random(cor*20));                  //膽識30*20=600
 }
 else if (maxskee > 150)
 {
   message_vision(HIM + "  殺      意      魔      氣\n\n" + NOR,me);
   message_vision(HIR + "超上級威力        *紅*級*魔*氣*   \n\n" + NOR,me);
   message_vision(HIR + "$N由自身爆出強烈的殺氣，這是一種帶有魔力的殺氣\n" + NOR,me);
   message_vision(HIR + "$N地獄般的魔氣瞬間籠罩$n，令其感到劇烈的恐懼感！\n" + NOR,me,target);
   target->start_busy(2);
   target->receive_damage("gin",random(mix_power));
   target->receive_damage("sen",random(cor*10));                          //膽識30*10=300
 }
 else if (maxskee > 100)
 {
   message_vision(HIM + "  殺      意      魔      氣\n\n" + NOR,me);
   message_vision(HIY + "上級威力          *黃*級*魔*氣*   \n\n" + NOR,me);
   message_vision(HIY + "$N由自身爆出強烈的殺氣，這是一種帶有魔力的殺氣\n" + NOR,me);
   message_vision(HIY + "$N地獄般的魔氣瞬間籠罩$n，令其感到劇烈的恐懼感！\n" + NOR,me,target);
   target->start_busy(2);
   target->receive_damage("gin",random(mix_power*0.9)); //max 249
   target->receive_damage("sen",random(cor*8));                         //膽識30*8=240
 }
 else if (maxskee > 70)
 {
   message_vision(HIM + "  殺      意      魔      氣\n\n" + NOR,me);
   message_vision(HIB + "中級威力          *藍*級*魔*氣*   \n\n" + NOR,me);
   message_vision(HIB + "$N由自身爆出強烈的殺氣，這是一種帶有魔力的殺氣\n" + NOR,me);
   message_vision(HIB + "$N地獄般的魔氣瞬間籠罩$n，令其感到劇烈的恐懼感！\n" + NOR,me,target);
   target->start_busy(1);                                     //busy 1
   target->receive_damage("gin",random(mix_power*0.8)); //max 249
   target->receive_damage("sen",random(cor*7));                         //膽識30*6=180
 }
 else if (maxskee > 40)
 {
   message_vision(HIM + "  殺      意      魔      氣\n\n" + NOR,me);
   message_vision(RED + "          *泛*級*魔*氣*   \n\n" + NOR,me);
   message_vision(RED + "$N由自身爆出強烈的殺氣，這是一種帶有魔力的殺氣\n" + NOR,me);
   message_vision(RED + "$N地獄般的魔氣瞬間籠罩$n，令其感到劇烈的恐懼感！\n" + NOR,me,target);
   target->start_busy(1);                                     //busy 1
   target->receive_damage("gin",random(mix_power*0.7)); //max 150
   target->receive_damage("sen",random(cor*6));                         //膽識30*6=180
 }
 else if (maxskee > 10)
 {
   message_vision(HIM + "  殺      意      魔      氣\n\n" + NOR,me);
   message_vision(MAG + "          *初*級*魔*氣*   \n\n" + NOR,me);
   message_vision(MAG + "$N由自身爆出強烈的殺氣，這是一種帶有魔力的殺氣\n" + NOR,me);
   message_vision(MAG + "$N地獄般的魔氣瞬間籠罩$n，令其感到劇烈的恐懼感！\n" + NOR,me,target);
   target->start_busy(1);                                     //busy 1
   target->receive_damage("gin",random(mix_power*0.5)); //max 120
   target->receive_damage("sen",random(cor*4));                         //膽識30*5=120
 }
   target->set_temp("mkill",1);
   target->apply_condition("mkill_out",mkilluse);
   return 1;
}

