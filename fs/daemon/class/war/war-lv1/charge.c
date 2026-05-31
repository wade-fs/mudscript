inherit SSERVER;
#include <ansi.h>
int perform(object me, object victim,string arg)
{	
        int damage;
        if(!victim) return notify_fail("你要對誰發動突擊??\n");     
        if(me->is_fighting()) return notify_fail("你跟對方大將殺的正起勁, 怎麼指揮突擊??\n"); //已進入戰鬥狀態無法突擊
        if(me->query("war/兵種")!="騎兵") return notify_fail("不是騎兵怎麼突擊啊!!\n"); //騎兵限定
        if(me->query("war/兵力值")<500) return notify_fail("你的兵力不足以發動突擊!!\n"); //避免無兵力突擊
        if(victim->query("war/兵力值")<1) return notify_fail("以多欺少勝之不武!!\n"); //對無兵力者不能發動
        
        if(victim->is_fighting()) //目標部隊已被牽制柱的情況
        {                                                       //由於對方部隊被牽制中, 我方部隊側面突擊, 傷害較大
        damage=500+me->query_skill("war-lv1",1)*10+me->query("functions/charge/level")*10; 
        message_vision(HIR"$N率領騎兵對$n軍發動側面突擊, 造成$n "+damage+" 人死傷!!\n"NOR ,me,victim);
        if (victim->query("war/兵力值") < damage && victim->query("war/兵力值") >= 1) //目標兵力比傷害值小直接擊潰
        {
        victim->set("war/兵力值",0);      //直接設定對方兵力為0
        victim->move("/open/wiz/hall1");  //移動到非戰區, 暫定為wiz hall, 將來可能是俘虜室
        message_vision(HIY"\n$N軍擊潰$n軍!!\n"NOR ,me,victim);
        me->add("war/兵力值",-random(20)); //自己的損傷
        me->add("war/戰場經驗",1);         //增加戰場經驗
        me->start_busy(5);  //重新佈陣時間, 避免過快重複突擊, 由於沒有進入戰鬥所以不會解除busy
        return 1;
        }
        victim->add("war/兵力值",-damage); //目標兵力大於傷害值, 給予其損傷
        me->add("war/兵力值",-random(20)); //自己的損傷
        me->add("war/戰場經驗",1);         //增加戰場經驗
        message_vision(HIW"\n戰力: "+me->query("name")+"軍 "+me->query("war/兵力值")+" V.S "+victim->query("name")+"軍 "+victim->query("war/兵力值")+" \n\n"NOR ,me,victim);  
        me->start_busy(5); //由於敵人部隊已跟幾方部隊交戰, 所以不強制進入戰鬥, 還可再發動下一波突擊
        return 1;
        } 
        
        if(!victim->is_fighting()) //敵人不在戰鬥的情況, 即為待命軍隊, 沒有被我方部隊牽制時
        {
        damage=300+me->query_skill("war-lv1",1)*5+me->query("functions/charge/level")*5; //由於對方待命中, 所以傷害較少
        message_vision(HIR"$N率領騎兵對$n軍發動正面突擊, 造成$n "+damage+" 人死傷!!\n"NOR ,me,victim);
        if (victim->query("war/兵力值") < damage && victim->query("war/兵力值") >= 1) //對方兵力小於損傷值, 直接擊潰
        {
        victim->set("war/兵力值",0);       //直接設定對方兵力為0
        victim->move("/open/wiz/hall1");   //移動到非戰區, 暫定為wiz hall, 將來可能是俘虜室
        me->add("war/兵力值",-random(20)); //自己的損傷
        me->add("war/戰場經驗",1);         //增加戰場經驗
        message_vision(HIY"\n$N軍擊潰$n軍!!\n"NOR ,me,victim);
        return 1;
        }
        victim->add("war/兵力值",-damage); //目標兵力大於傷害值, 給予其損傷
        me->add("war/兵力值",-random(20)); //自己的損傷
        me->add("war/戰場經驗",1);         //增加戰場經驗
        message_vision(HIW"\n戰力: "+me->query("name")+"軍 "+me->query("war/兵力值")+" V.S "+victim->query("name")+"軍 "+victim->query("war/兵力值")+" \n\n"NOR ,me,victim);  
        victim->kill_ob(me);  //由於對方沒被我方部隊牽制, 所以強制交戰, 無法二度進行突擊
        me->kill_ob(victim);
        return 1;
        } 
}
 
