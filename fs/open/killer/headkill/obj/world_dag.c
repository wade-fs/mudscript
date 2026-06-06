//87.10.11  改成使用hit_ob來驅動特攻，
//          所以把heart_beat拿掉!!
//補上 有攻擊就要有狀態表示 減少死的莫名其妙的情況 by blazakira 2011/8/6
// 並將傷害方式add(xxx) >> receive_damage?

#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
//  seteuid(getuid());
  set_name(HIR"絕"+HIY"世"+HIG"匕"+HIC"首"NOR,({"world"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "把");
    set("long","匕首上刻有四門之圖騰，整支匕首散發出無比的力量。\n");
    set("value",20000);
    set("material", "steel");
    set("no_sell",1);
    set("no_auc",1);
    set("no_drop",1);
    set("no_steal",1);
    set("no_give",1);
    set("no_hands",1);
    set("weapon_prop/dagger",20);
  }
  set("wield_msg",HIR"$N"HIR"將$n"HIR"握在手上，全身充滿著無限的力量。\n"NOR);
  set("unwield_msg",HIY"$N"HIY"畫出一道銀花，將$n"HIY"放回身邊小袋中。\n"NOR);
  init_dagger(95);
  setup();
}

mixed hit_ob( object victim,object me)
{
  object user=environment();
  int a,b,c,i,bell,shalv,maglv,doglv,cor;
  int chiso,world_choice;

  user=this_player();
  bell  = user->query("bellicosity");
  shalv = user->query_skill("shadow-kill",1);
  maglv = user->query_skill("magic",1);
  doglv = user->query_skill("dodge",1);
  cor   = user->query_cor();

  if( user->is_fighting() && query("equipped") )
  {
    victim->set_temp("last_damage_from", user); //既然發動就先在對手身上標記攻擊方為誰 by blazakira
    //代表魔氣殺最少要有60級以上，才有機會驅動四神合一第一式
    //目前也只寫第一，二式
    if (random(user->query("functions/manakee/level") ) > 60)
    { //如果玩家練魔氣殺練到LV 100的話，發動機率約為40％
      //但是，一般而言目前最多都沒練到LV 60
      //但為避免還是有人練到，導致威力太強，所以在加上一個機率
      if(random(user->query_skill("rain-throwing",1)) >  80 && user->query("bellicosity") > 500 && user->query("atman") > 100 && user->query("force") > 500)
      { //因為，rain-throwing的等級最高100，所以max機率將是 0.4*0.2=0.08
        message_vision(HIR"\n四  "+HIG"神  "+HIY"合  "+ HIC"一    "+HIW"～"NOR,victim);
        message_vision(HIW"～    "HIM"ψ四☆★☆神☆★☆暴☆★☆走ψ\n"NOR,victim);
        message_vision(YEL"匕首中竄出一道玄武幻影，包圍$N!!\n"NOR,victim);
        message_vision(HIC"匕首中竄出數十道白虎幻影，牽制$N的攻勢!!\n"NOR,victim);
        message_vision(HIG"青龍由匕首上衝出，直接衝向$N!!\n"NOR,victim);
        message_vision(HIR"巨大的火鳳凰飄然降臨，$N四周彷彿揚起地獄的業火!!\n"NOR,victim);
        //玄武的
        chiso=random(cor+doglv);
        victim->add("gin",-chiso);
        victim->add("sen",-chiso);
        user->add("kee",chiso);
        //白虎的
        victim->start_busy(2);
        //青龍的
        victim->add("gin",-((cor+maglv)*3));
        victim->add("sen",-((cor+maglv)*3));
        //朱雀的
        victim->receive_damage("kee",random(shalv*2.8),user);
        COMBAT_D->report_status(victim);
        //玩家所必須付出的代價
        //user->add("bellicosity",-(user->query("bellicosity")/10));
        //user->add("atman",-(user->query("atman")/3));
        //user->add("force",-(user->query("force")/8));
        user->add("bellicosity",-50);
        user->add("atman",-30);
        user->add("force",-50);
        return ;
      }
    }
    //四神合一第二式，發動最基本條件，閻影匕首 lv 70,魔氣殺lv 80
    //閻影匕首最高lv90，魔氣殺是func且不是內力型，一定要打敵人練，蠻難練的
    //manakee目前玩家最高練到60左右
    //若以魔氣殺第二段限制lv 100與閻影匕首最高lv 90來算
    //最高機率是 (90-70)/90 * 0.2=0.22*0.2=0.044=4.4%的發動機率
    //至於玩家所需付出的代價，因為都是四神合一，所以一樣
    //代價：內力的1/8，殺氣的1/10，靈力的1/3，可以說是用自己的生命去換取勝利
    //傷害是看發動哪一位霸主，每一個都有所不同
    if (random(user->query("functions/manakee/level") ) > 80)
    { //如果玩家練魔氣殺練到LV 100的話，發動機率約為20％
      //但是，一般而言目前最多都沒練到LV 50
      //但為避免還是有人練到，導致威力太強，所以在加上一個機率
      if(random(user->query_skill("shadow-kill",1)) >  70 && user->query("bellicosity") > 500 && user->query("atman") > 100 && user->query("force") > 500)
      {
        message_vision(HIR"\n四  "+HIG"神  "+HIY"合  "+ HIC"一    "+HIW"～"NOR,victim);
        message_vision(HIW"～    "HIM"ψ四☆★☆神☆★☆霸☆★☆主ψ\n"NOR,victim);
        world_choice=random(4);
        switch(world_choice)
        {
          case 0: //玄武霸主
          {
            //message_vision(HBYEL"\n◎◎◎◎◎◎▁▂▃▄▅▆▇█▇▆▅▄▃▁◎◎◎◎◎◎\n"NOR,victim);
            message_vision(YEL"玄武稱霸四神，化身成為玄武霸主，籠罩住$N四周!!\n"NOR,victim);
            message_vision(YEL"$N感到全身的精力似乎被玄武霸主所剝奪!!\n"NOR,victim);
            message_vision(YEL"玄武霸主由$N回到四神匕首，你感到全身精神為之一振!!\n"NOR,victim);
            //message_vision(HBYEL"\n◎◎◎◎◎☆◎★◎↑↓←→↖↗↙↘◎★◎☆◎◎◎◎◎\n"NOR,victim);
            //玄武霸主的傷害
            chiso=random(cor+doglv);
            victim->add("gin",-(chiso*3));
            victim->add("sen",-(chiso*3));
            user->add("gin",chiso*2);
            user->add("sen",chiso*2);
            break;
          }
          case 1://白虎霸主
          {
            //message_vision(HBCYN"\n◎◎◎◎◎◎▁▂▃▄▅▆▇█▇▆▅▄▃▁◎◎◎◎◎◎\n"NOR,victim);
            message_vision(HIC"白虎稱霸四神，化身成為白虎霸主，牽制$N的攻勢!!\n"NOR,victim);
            message_vision(HIC"$N的攻勢為之一滯，似乎施展不開來。。。\n"NOR,victim);
            message_vision(HIC"$N強硬擺\脫白虎霸主的控制，身體受到嚴重的創傷!!\n"NOR,victim);
            //message_vision(HBCYN"\n◎◎◎◎◎☆◎★◎↑↓←→↖↗↙↘◎★◎☆◎◎◎◎◎\n"NOR,victim);
            //白虎霸主的傷害
            victim->start_busy(2);
            victim->add("kee",-(cor*3));
            break;
          }
          case 2://青龍霸主
          {
            //message_vision(HBGRN"\n◎◎◎◎◎◎▁▂▃▄▅▆▇█▇▆▅▄▃▁◎◎◎◎◎◎\n"NOR,victim);
            message_vision(HIG"青龍稱霸四神，化身成為青龍霸主，衝向$N，透體而過!!\n"NOR,victim);
            message_vision(HIG"$N感到一陣排山倒海的壓力迎面而來，宛如世界末日一般!!\n"NOR,victim);
            message_vision(HIG"青龍霸主的強大威力，令$N精神受到嚴重打擊!!\n"NOR,victim);
            //message_vision(HBGRN"\n◎◎◎◎◎☆◎★◎↑↓←→↖↗↙↘◎★◎☆◎◎◎◎◎\n"NOR,victim);
            //青龍霸主的傷害
            victim->add("gin",-random((cor+maglv)*5));
            victim->add("sen",-random((cor+maglv)*5));
            break;
          }
          case 3://朱雀霸主
          {
            //message_vision(HBRED"\n◎◎◎◎◎◎▁▂▃▄▅▆▇█▇▆▅▄▃▁◎◎◎◎◎◎\n"NOR,victim);
            message_vision(HIR"朱雀稱霸四神，化身成為朱雀霸主--幻之火鳳凰，$N看呆!!\n"NOR,victim);
            message_vision(HIR"$N四周揚起地獄的業火，熊熊的烈火環繞身軀!!\n"NOR,victim);
            message_vision(HIR"地獄般的業火，在$N身上熊熊的燃燒著!!\n"NOR,victim);
            message_vision(HIR"這種痛苦的感覺另$N感到身上的一切似乎已不再屬於自己!!\n"NOR,victim);
            //message_vision(HBRED"\n◎◎◎◎◎☆◎★◎↑↓←→↖↗↙↘◎★◎☆◎◎◎◎◎\n"NOR,victim);
            //朱雀霸主的傷害
            victim->receive_damage("kee",random(shalv*5),user);
            break;
          }
        } //switch block的外圍，由case裡面的break將會跳到這裡
        //玩家所必須付出的代價
        //user->add("bellicosity",-(user->query("bellicosity")/15));
        //user->add("atman",-(user->query("atman")/3));
        //user->add("force",-(user->query("force")/10));
        user->add("bellicosity",-30);
        user->add("atman",-10);
        user->add("force",-30);
        COMBAT_D->report_status(victim);
        return ;
      } //end if
    } //end if random()
   
    //上面是屬於四神合一的特攻階段
    if(random(100) > 80)   //新玄武特攻，土系，吸收型  30％發動成功
    {
      message_vision(YEL"由絕世匕首中竄出一道玄武幻影，包圍$N!!巨大的玄武幻影，將$N吞噬!!\n"NOR,victim);
      message_vision(HIM"$n被$N的玄武幻影所侵襲，精神流失被$N所吸收!!"NOR"\n",user,victim);
      //表閃躲能力越好，被打中的％越少
      chiso=random((cor*2)+(doglv/2));
      victim->add("gin",-chiso);
      victim->add("sen",-chiso);
      user->add("kee",chiso);
      user->add("gin",chiso);
      user->add("sen",chiso);
      COMBAT_D->report_status(victim);
      //防止吸超過上限
      if(user->query("sen") > user->query("max_sen"))
      {
        a=user->query("max_sen");
        user->set("sen",a);
      }
      if(user->query("gin") > user->query("max_gin"))
      {
        b=user->query("max_gin");
        user->set("gin",b);
      }
      if(user->query("kee") > user->query("max_kee"))
      {
        c=user->query("max_kee");
        user->set("kee",c);
      }
      return ; //因為已經發動這一項，所以不可以再發動其他特攻
    } //以上是玄武特攻的發動設定 

    if(random(100) > 80) //新白虎特攻，冰系，牽制型 30%發動成功
    {
      message_vision(HIC"由絕世匕首中竄出數十道白虎幻影，牽制$N的攻勢，白虎幻影干擾著$N的視線，致使攻勢為之一滯!!\n"NOR,victim);
      if (doglv > victim->query_skill("dodge",1))
        victim->start_busy(2);
      else 
        victim->start_busy(1);
      message_vision(HIC"$N受到白虎幻影的牽制，而無法行動!!\n"NOR,victim);
      return ;
    } //以上是白虎特攻的發動設定

    if(random(100) > 80) //新青龍特攻，風系，精神傷害系 30%發動成功
    {
      message_vision(HIG"青龍由匕首上衝出，直接衝向$N!!青龍幻影穿身而過，對$N的精神上以造成強大傷害!!\n"NOR,victim);
      if( bell > 4000)
      { //代表具有強大的殺氣，可以對精神上造成更大的傷害
        victim->add("gin",-(cor*5));
        victim->add("sen",-(cor*5));
        message_vision(HIG"$N精神上受到非常嚴重的創傷!!\n"NOR,victim);
        return ;
      }
      else if( bell > 2000)
      { //代表具有強大的殺氣，可以對精神上造成更大的傷害
        victim->add("gin",-(cor*4));
        victim->add("sen",-(cor*4));
        message_vision(HIG"$N精神上受到嚴重的創傷!!\n"NOR,victim);
        return ;
      }
      else if( bell > 1000)
      { //代表具有強大的殺氣，可以對精神上造成更大的傷害
        victim->add("gin",-(cor*3));
        victim->add("sen",-(cor*3));
        message_vision(HIG"$N精神上受到普通的創傷!!\n"NOR,victim);
        return ;
      }
      else if( bell > 100)
      { //代表具有強大的殺氣，可以對精神上造成更大的傷害
        victim->add("gin",-(cor*2));
        victim->add("sen",-(cor*2));
        message_vision(HIG"$N精神上受到輕微的創傷!!\n"NOR,victim);
        return ;
      }
      return ;
    } //以上是青龍的發動設定

    if(random(100) > 70)  //新朱雀特攻，火系，肉體傷害型 40%發動成功
    {
      if (shalv >80)
      { //閻影匕首越強，威力越大，LV最高90所以最高是 252點傷害
        message_vision(HIR"巨大的火鳳凰飄然降臨，$N四周彷彿揚起地獄的業火，$N被地獄的業火所灼，肉體遭到非常嚴重的傷害!!\n"NOR,victim);
        victim->receive_damage("kee",random(shalv*2.8),user);
        COMBAT_D->report_status(victim);
        return ;
      }
      else if (shalv >60)
      { //閻影匕首越強，威力越大
        message_vision(HIR"$N四周揚起地獄的業火，熊熊的烈火將四周包圍，在烈火中傳出$N淒厲的哀嚎聲，其肉體遭到嚴重的創傷!!\n"NOR,victim);
        victim->receive_damage("kee",random(shalv*2.2),user);
        COMBAT_D->report_status(victim);
        return ;
      }
      else if (shalv >40)
      { //閻影匕首越強，威力越大
        message_vision(HIR"朱雀所揚起的熊熊烈火，在$N四周燃燒著，$N一不小心被烈火所傷，身體受到不少燒傷!!\n"NOR,victim);
        victim->receive_damage("kee",random(shalv*1.6),user);
        COMBAT_D->report_status(victim);
        return ;
      }
      else if (shalv > 1)
      { //閻影匕首越強，威力越大
        message_vision(HIR"絕世匕首發出刺眼的火光，令$N眼睛受到傷害，$N攻勢為之一滯!!\n"NOR,victim);
        victim->receive_damage("kee",random(shalv),user);
        victim->start_busy(1);
        COMBAT_D->report_status(victim);
        return ;
      }
      else if (shalv <= 1)
      { //考慮到目前world是開放的，所以，有些門派沒有shadow-kill
        message_vision(HIR"絕世匕首發出刺眼的火光，令$N眼睛受到傷害，$N攻勢為之一滯!!\n"NOR,victim);
        victim->start_busy(1);
        COMBAT_D->report_status(victim);
        return ;
      }
    } //以上是朱雀的發動設定
    //代表發動失敗
    tell_object(user,"四神均毫無動靜!!\n");
    return;
  } //這是檢查有沒有在戰鬥中的那一個if的block
} //函示結束的block
