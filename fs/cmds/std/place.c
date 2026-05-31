//place.c by bss
//瞬間移動之術, 配合/feature/place.c
//有完整的迷, 才有可能開放
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int i,num;
    mapping places;
    string txt,verb, replace, *vrbs;
    object room;

    places=me->query_all_place();
    txt="";
    if(!me->query("quests/can_transmit")) return 0;
    if( !arg ) {
      if( !sizeof(places) ) {
        write("你目前並沒有設定任何 places。\n");
        return 1;
      } else  {
        write("你目前設定的傳送地點記載如下﹕\n");
        txt+=sprintf("%4s %7s","編號","地點");
        if(wizardp(me))
          txt+=sprintf("%24s\n","檔名");
        else
          txt+="\n";
        num=sizeof(places);
        for(i=0; i<num; i++){
          txt+=sprintf("(%2d)\t%-20s",i+1,me->query_place(i,"name"));
          if(wizardp(me))
            txt+=sprintf("\t%-23s\n",me->query_place(i,"file_name"));
          else
            txt+=sprintf("\n");
        }
        me->start_more(txt);
        return 1;
      }
    }
    if(sscanf(arg,"%s %d",verb,num)!=2){
      if(arg=="set"){
        room=environment(me);
        num=sizeof(places);
        me->set_place(room,num);
        return 1;
      }
       else if(arg=="delete_all")
            return me->delete_all_place();
      else return 0;
    }
    else{
      if(verb=="go"){
        replace=me->query_place(num-1,"file_name");
        if(!me->query("env/NoTransmitMSG"))
          message_vision( HIC+"$N將食中指點在額頭，使出瞬間移動之術，「咻.....」的一聲，$N消失在眾人眼前!\n"+NOR ,me);
        if( !me->move(replace) ){
          write("你發現你還在原地動也不動, 似乎是法術出了點問題。 \n");
          write("最好通知一下wiz吧!!\n");
          return 1;
        }
        if(!me->query("env/NoTransmitMSG"))
          message_vision(HIC+"「咻～～～～」的一聲，$N突然出現在眾人眼前!\n"+NOR,me);
        return 1;
      }
      if(verb=="-d"){
        me->delete_place(num-1);
        return 1;
      }
      if(verb=="display"){
        replace=me->query_place(num-1,"file_name");
        if(!replace)
          return notify_fail("沒有這個傳送點!!\n");
        if(objectp(room=find_object(replace)))
          "/cmds/std/look.c"->look_room(me,room,1);
        else{
          call_other(replace, "???");
          "/cmds/std/look.c"->look_room(me, find_object(replace),1);
        }
        return 1;
      }
      else return 0;
    }
    return 0;
}
int help(object me)
{
    if(!me->query("quests/can_transmit")) return 0;

    write(@HELP
指令格式 : place [set | -d | go | display] >
指令說明 :
        這個指令主要是方便你在主大陸的移動, 類似一個法術
        可以將你傳送到你之前設定的地方。
範例:
        'place set :會把你目前所在的位置記起來, 方便以後傳送
        'place -d 數字:把編號某一號的記憶消除掉
        'place :顯示你目前所有的記憶地點
        'place display 數字:可以用千里眼之術看看該地點目前的情況
        'place go 數字:把自己傳送到記憶地點, 會損一半的氣
HELP
);
    return 1;
}

