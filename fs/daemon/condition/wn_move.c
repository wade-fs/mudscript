//戰功忍者專用的移動判斷
//會出現莫名停止的狀態 應該是非玩家 會被系統給停止心跳 停止狀態之類的

#include <ansi.h>
int update_condition(object me, int duration)
{
//  if(me->query("assassin") != "assassination ninja") return 0;
  object *enemy,env,*user,ppl,rooms;
  string object_id="",room="";
  int i,k;
  if( !me ) return 0;
  if( me->is_fighting() ) return 1; //戰鬥中無法前往下個目標。
  if( duration < 1 ) {
//    me->move("/open/capital/room/king/kr4-4-5");
    return 0;
  }
//於門派首領處 停頓時間設定 //尚未完成
  if( duration >= 6 ) {
    me->apply_condition("wn_move",duration-1);
    return 1;
  }

//狀態提示用 不然都不知道npc是否停止心跳了
  ppl=find_player("blazakira");
  if(ppl)
    if(!ppl->query("env/wn_msg_off"))
      tell_object(ppl,BRED+HIC+"暗殺行動中，但是不一定移動成功\，因為有打過就會重新等待再判斷。\n"+NOR);

  if ( me->query_temp("master/target_finish") ) { //抵達天子的mark 做額外判定作為持續狀態的判定
    if( object_id && me->query("assassin") == "assassination ninja") {
      me->apply_condition("wn_move",0);
      me->do_command("kill king");
    }
    else if( object_id )
//      me->kill_ob(enemy[i]);
      me->do_command("kill king");
    return 1;
  }
/* //使用碼頭的迴圈判斷來輔助 //測試此形式 故暫忽略之
//尋找玩家為 同意參加反暗殺任務（協防任務
  user = users();
  ppl=find_player("blazakira");
  if(!userp(me)) { //非玩家才會有被系統停止心跳的問題
    //先定位 所以先到recall紀錄位置
    if (!me->query_temp("room")) {
      me->do_command("recall"); //跑到血魔處時會不能recall
      me->set_temp("room",environment(me));
      return 1; //重新判斷 所以再跑一次condition
    }
    if(me->query_temp("room")!=environment(me)) { //當rooms不存在時 也不會與npc為同一個房間
      me->do_command("recall"); //跑到血魔處時會不能recall
      me->do_command("eat mapo doufu");
      me->do_command("drink tea");
    }
*/
/*
    if(ppl) {
      if(!ppl->query("env/wn_msg_off"))
        tell_object(ppl,BMAG+HIW+""+me->query("name")+"出現在你眼前，準備移動下個目標中。\n"+NOR);
      rooms=environment(ppl);
      me->move(rooms);
      if(me->query_temp("target_room")) me->move(me->query_temp("target_room")); //回到原先的地方
    }
    else if(sizeof(user) >1) {
      for(i=0;i<sizeof(user);i++) {
        if(!living(user[i])) continue;
        if(!user[i]->query_temp("quests/assassin/accept")) continue;
        rooms=environment(user[random(sizeof(user))]);
        if(!rooms) rooms=environment(user[i]);
        me->move(rooms);
        if(me->query_temp("target_room")) me->move(me->query_temp("target_room"));
      }
    }
  }
*/
//  if(!userp(me))
//    me->set("random_move",1000);
  i=random(19);
  if( me->query_temp("master/times") > 14 ) //將18的門派首領數量降低 避免有玩家針對門派首領掛網 而導致暗殺活動失敗
    i=19;
  switch( i ) { //如果不使用return而是讓npc自己跑下一家呢 //或者做額外的move函數 直接再做判斷後移動? //或者是當作停留時間 作為讓玩家去尋找npc的時間?
    case 1:
      room = "/open/killer/room/masterm";
      if(me->query_temp("master/killer")) {
        return 1;
      }
      break;
    case 2:
      room = "/open/tendo/room/start";
      if(me->query_temp("master/tendo")) {
        return 1;
      }
      break;
    case 3:
      room = "/open/gsword/room/g5-1";
      if(me->query_temp("master/gsword")) {
        return 1;
      }
      break;
    case 4:
      room = "/open/dancer/room/start";
      if(me->query_temp("master/dancer")) {
        return 1;
      }
      break;
    case 5:
      room = "/open/poison/room/room1";
      if(me->query_temp("master/poison")) {
        return 1;
      }
      break;
    case 6:
      room = "/open/wu/room/luroom18";
      if(me->query_temp("master/wu")) {
        return 1;
      }
      break;
    case 7:
      room = "/open/beggar/room/beg2/main";
      if(me->query_temp("master/beggar")) {
        return 1;
      }
      break;
    case 8:
      room = "/open/gblade/room/gblade";
      if(me->query_temp("master/gblade")) {
        return 1;
      }
      break;
    case 9:
      room = "/open/ping/room/p1";
      if(me->query_temp("master/duan")) {
        return 1;
      }
      break;
    case 10:
      room = "/open/gblade/room/secret";
      if(me->query_temp("master/mou")) {
        return 1;
      }
      break;
    case 11:
      room = "/open/snow/room/room2";
      if(me->query_temp("master/snow")) {
        return 1;
      }
      break;
    case 12:
      room = "/open/scholar/room/r17";
      if(me->query_temp("master/scholar")) {
        return 1;
      }
      break;
    case 13:
      room = "/open/badman/room/g1";
      if(me->query_temp("master/badman")) {
        return 1;
      }
      break;
    case 14:
      room = "/open/doctor/room/2";
      if(me->query_temp("master/doctor")) {
        return 1;
      }
      break;
    case 15:
      room = "/open/prayer/room/punch1";
      if(me->query_temp("master/prayer")) {
        return 1;
      }
      break;
    case 16:
      room = "/open/marksman/room/room1-31";
      if(me->query_temp("master/marksman")) {
        return 1;
      }
      break;
    case 17:
      room = "/open/gsword/room1/blood1/r10";
      if(me->query_temp("master/bloodking")) {
        return 1;
      }
      break;
    case 18:
      room = "/open/bonze/room/big";
      if(me->query_temp("master/bonze")) {
        return 1;
      }
      break;
    case 0:
      room = "/open/capital/room/chen_home";
      if(me->query_temp("master/capital")) {
        return 1;
      }
      break;
    default :
      room = "/open/capital/room/king/kr4-4-5";
      me->set_temp("master/target_finish",1); //抵達天子的mark 做額外判定作為持續狀態的判定
      break;
  } //switch end
//  me->set_temp("target_room",room);

  me->delete_busy();
//  if(!rooms) rooms=me->query_temp("room");
//  if(rooms) rooms->delete("no_clean_up");
  message_vision("$N扔下一枚煙霧彈之後消失在眾人眼前。\n", me);
  ppl=find_player("blazakira");
  if(ppl) tell_object(ppl,BYEL+HIG+"\n"+me->query("name")+"的下一個目的地為"+HIY+room+HIG+"。\n\n"+NOR);
  me->move(room);
//  rooms=environment(me);
//  me->set_temp("room",rooms);
//  if(rooms) rooms->set("no_clean_up",1);
  message_vision("從房間的陰影中$N的身影突然出現。\n", me);
  enemy=all_inventory( environment(me) ); //為房間的所有物件
//移動之後就減一
//  me->apply_condition("wn_move",duration-1); //原則上不刪除本狀態才對 //或者考慮跑道天子那裡就停下來 改用心跳攻擊天子

//判斷移動後該房間的npc是否符合master之一
  if(sizeof(enemy) >1) { //目的地除了npc以外還有別的npc or 玩家在的話 就往下判斷
    for(i=0;i<sizeof(enemy);i++) {
      if(enemy[i]==me) continue; //如果是自己就忽略
      if(!living(enemy[i])) continue; //如果不是活著就就忽略（含佈告版或其他等物件）
      if(userp(enemy[i])) continue; //如果是玩家就忽略吧 不然砍死玩家會很麻煩XD
      object_id=enemy[i]->query("id"); //讀入id作為判斷
      switch( object_id ) {
        case "master yar":
          if(!me->query_temp("master/killer")) {
            me->set_temp("master/killer",1);
          }
          break;
        case "master lu":
          if(!me->query_temp("master/tendo")) {
            me->set_temp("master/tendo",1);
          }
          break;
        case "master teng":
          if(!me->query_temp("master/gsword")) {
            me->set_temp("master/gsword",1);
          }
          break;
        case "master yua":
          if(!me->query_temp("master/dancer")) {
            me->set_temp("master/dancer",1);
          }
          break;
        case "master low":
          if(!me->query_temp("master/poison")) {
            me->set_temp("master/poison",1);
          }
          break;
        case "master jen":
          if(!me->query_temp("master/wu")) {
            me->set_temp("master/wu",1);
          }
          break;
        case "master su":
          if(!me->query_temp("master/beggar")) {
            me->set_temp("master/beggar",1);
          }
          break;
        case "master ba":
          if(!me->query_temp("master/gblade")) {
            me->set_temp("master/gblade",1);
          }
          break;
        case "lord duan":
          if(!me->query_temp("master/duan")) {
            me->set_temp("master/duan",1);
          }
          break;
        case "master mou":
          if(!me->query_temp("master/mou")) {
            me->set_temp("master/mou",1);
          }
          break;
        case "master liu":
          if(!me->query_temp("master/snow")) {
            me->set_temp("master/snow",1);
          }
          break;
        case "master sue":
          if(!me->query_temp("master/scholar")) {
            me->set_temp("master/scholar",1);
          }
          break;
        case "du sa":
          if(!me->query_temp("master/badman")) {
            me->set_temp("master/badman",1);
          }
          break;
        case "master tor":
          if(!me->query_temp("master/doctor")) {
            me->set_temp("master/doctor",1);
          }
          break;
        case "pope lin":
          if(!me->query_temp("master/prayer")) {
            me->set_temp("master/prayer",1);
          }
          break;
        case "master lee":
          if(!me->query_temp("master/marksman")) {
            me->set_temp("master/marksman",1);
          }
          break;
        case "bloodking":
          if(!me->query_temp("master/bloodking")) {
            me->set_temp("master/bloodking",1);
          }
          break;
        case "master of bonze":
          if(!me->query_temp("master/bonze")) {
            me->set_temp("master/bonze",1);
          }
          break;
        case "master chen":
          if(!me->query_temp("master/capital")) {
            me->set_temp("master/capital",1);
          }
          break;
        case "king":
          break;
        default :
          continue; //如果是其他npc 就忽略吧
          break;
      } //switch end
      if( object_id && me->query("assassin") == "assassination ninja")
        me->do_kill(me,enemy[i]);
      else if( object_id )
        me->kill_ob(enemy[i]);
      me->add_temp("master/times",1); //有殺就算增加
    } //for end
  }
  duration=8;
//  me->apply_condition("wn_move",10);
  return 1;
}
