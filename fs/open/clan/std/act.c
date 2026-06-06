/*.
1.移動: 作了這個動作後,移動到某些房間去.
2.出現一條路:作了這一些以後,出現了一條路.
3.出現一隻mob:作了動作以後,跑出一隻mob 出來.
4.找到東西:作了這些動作以後,身上多了一個東西.
                    make by avgirl 00/06/28
*/
/*增加撿查幫派的功能                  *
 *               by avgirl 00/09/06   */

inherit ROOM;

int action_move(string,string);
int link_way(string arg,string opt);
int type(string verb,string ftype);
int add_mob(string arg,string opt);
int find_obj(string arg,string opt);
object env;
void init()
{
int dof;
mapping dom;

     env = environment(this_player());
        dof = sizeof(env->query("action"));

        if(dof != 0) {
                dom = env->query("action");
                add_action("action", keys(dom));
        }
}
int action(string arg)
{
        string keyword,verb,type,err_msg,check_ob,clan,*ally;
        object obj;
        int check_clan;


        verb = query_verb();
        keyword = env->query("action/"+verb+"/keyword");
        type = env->query("action/"+verb+"/type");
        err_msg = env->query("action/"+verb+"/err_msg");
        check_ob = env->query("action/"+verb+"/check_ob");
        check_clan = env->query("action/"+verb+"/check_clan");
        sscanf(base_name(env),"/open/clan/%s/%*s",clan);
        ally = CLAN_D->clan_query( this_player()->query("clan/id"), "ally" );

         if(!env->query("action/"+verb+"/filename")&& env->query("action/"+verb+"/filename")=="")
                return notify_fail("這個指令尚未完成。\n");
        if(!type) return notify_fail("這個指令尚未完成。\n");

// 這邊是檢查幫派的部份.
        switch(check_clan){
// 1時..就非本幫的不能使用...        
        case 1:
        if(this_player()->query("clan/id") != clan)
                return 0;
        break;
// 2.非同盟幫的不能使用.
        case 2:
        if(member_array( clan, ally ) == -1 && 
           this_player()->query("clan/id") != clan)
                return 0;
        default:
        }


        
        if(arg && keyword=="") return notify_fail(err_msg+"\n");  
        else if(keyword != "" && (!arg || arg != keyword)) return notify_fail(err_msg+"\n");
        if(check_ob && !obj=present(check_ob,this_player()))
                return notify_fail(err_msg+"\n");
        if(obj) destruct(obj);

        type(verb,"action");
return 1;
}

int type(string verb,string ftype)
{
        string type,filename,check;
        type = env->query(ftype+"/"+verb+"/type");
        filename  = env->query(ftype+"/"+verb+"/filename"); 
//下面是防作弊檢查
// 只檢查幫派的區域,幫派以外的區域不給inherit...
       if(filename!="" && sscanf(filename,"/open/clan/%s/%*s",check)!=2){
        log_file("clan/move_bug",sprintf("[%s] %s(%s)的房間 filename 為 %s\n",
            ctime(time()),
                        this_player()->name(),
                        getuid(this_player()),
filename,
        base_name(env)));
                return 0;
        }
// 以下是撿查該用那一種的移動,或招換..之類的..
// 並各自呼叫各字的fun...

        switch(type){

        case "action_move":
                action_move(ftype,verb);
        break;

        case "link_way":
                link_way(ftype,verb);
        break;

        case "add_mob":
                add_mob(ftype,verb);
        break;

        case "find_obj":
                find_obj(ftype,verb);
        break;

        }
        return 1;


}

int action_move(string arg,string opt)
{

/*
需要4個必要的敘述:
1.使用後本身看到敘述.(msg)
2.移動前這間房間看的到的敘述.(before_msg)
3.疑動後得房間所看到的敘述.(later_msg)
4.移動到的房間的檔名.(filename)
*/
        string msg, before_msg, later_msg, filename;

        filename = env->query(arg+"/"+opt+"/filename");
        msg = env->query(arg+"/"+opt+"/msg");
        before_msg = env->query(arg+"/"+opt+"/before_msg");
        later_msg = env->query(arg+"/"+opt+"/later_msg");

//        seteuid(getuid());
        tell_object( this_player() , msg+"\n" );

// 顯示訊息...
        message_vision( before_msg+"\n" , this_player() );

// 把你移到新房間...
        this_player()->move(filename);

// 顯示訊息...
        message_vision( later_msg+"\n" , this_player() );
        return 1;
}
int link_way(string arg,string opt)
{
/*
需要5個必要的:
1.本身看到的敘述,(msg)
2.使用後,出現的敘述,(before_msg)
3.開啟連結的方向,一定不會跟原有的方向重覆的.(path)
4.連結房間的file.(filename)
5.關閉連結時的敘述.(later_msg)
ps.這條路開啟的時間是60秒.
*/
        string msg, before_msg, path, filename;
        filename = env->query(arg+"/"+opt+"/filename");
        msg = env->query(arg+"/"+opt+"/msg");
        before_msg = env->query(arg+"/"+opt+"/before_msg");
        path = env->query(arg+"/"+opt+"/path");

// 假如以經有這一條路了且還開過了,就不能開了..
        if(env->query("exits/"+path) &&
           env->query_temp("exits/"+path)) {
           write("路已經開了。\n");
           return 0;
           }

// 顯示訊息
        tell_object( this_player() , msg+"\n" );
        message_vision( before_msg+"\n" , this_player() );

// 暫存房間計錄..
        set_temp("exits/"+path,env->query("exits/"+path));

// 開始連接房間....
        set("exits/"+path,filename);

// 開啟後60秒關閉這邊出口..
        call_out("remove_link",60,arg,opt);
return 1;
}
int remove_link(string arg,string opt)
{
        string path, later_msg;

        later_msg = env->query(arg+"/"+opt+"/later_msg");
        path = env->query(arg+"/"+opt+"/path");

// 顯示訊息
       tell_room(env,later_msg+"\n");

// 刪掉新增的出口...
        delete("exits/"+path);

// 假如原先出口的話,恢復原先的出口...
        if(env->query_temp("exits/"+path)){
        env->set("exits/"+path,env->query_temp("exits/"+path));
        }

// 刪掉計錄
        delete_temp("exits/"+path);
        return 1;
}
int add_mob(string arg,string opt)
{
/*
需要以下幾個參數:
1.本身看到的敘述,(msg)
2.使用後,這個房間所看到的敘述,(before_msg)
3.招喚mob 的檔名,(filename)
4.招換後,可以看到的敘述(later_msg)
*/
        object mob;
        mapping ob_list;
        string msg, before_msg, later_msg, filename;

        ob_list=query_temp("clan_objects");
        filename = env->query(arg+"/"+opt+"/filename");
        msg = env->query(arg+"/"+opt+"/msg");
        before_msg = env->query(arg+"/"+opt+"/before_msg");
        later_msg = env->query(arg+"/"+opt+"/later_msg");

// 這邊是設定如果被招喚過了,就不會在出來了.(ps.理論上可行.)
// 房間於重生後將會重新set_temp("object")所以重生後才能在叫.

        mob=new(filename);

// 設定不能重覆拿的部份..
        if(ob_list){
 if(ob_list[filename] || !objectp(ob_list[filename])){
        destruct(mob);
        write(env->query("action/"+opt+"/err_msg")+"\n");
                return 1;
        }
        ob_list +=  ([filename:mob]) ;
        } else ob_list =  ([filename:mob]) ;

// 顯示訊息
        tell_object( this_player() , msg+"\n" );
        message_vision( before_msg+"\n" , this_player() ,mob);

// 把mob 移到你的房間去...
        mob->move(env);
        env->set_temp("clan_objects",ob_list);

// 顯示訊息
        message_vision( later_msg+"\n" , this_player() ,mob);
        return 1;
}


int find_obj(string arg,string opt)
{
/*
需要以下幾個參數:
1.本身看到的敘述,(msg)
2.下指令後,這個房間所看到的敘述,(before_msg)
3.拿到物品的檔名,(filename)
4.拿到後,可以看到的敘述(later_msg)
*/
        object mob;
        mapping ob_list;
        string msg, before_msg, later_msg, filename;

        ob_list=query_temp("clan_objects");
        filename = env->query(arg+"/"+opt+"/filename");
        msg = env->query(arg+"/"+opt+"/msg");
        before_msg = env->query(arg+"/"+opt+"/before_msg");
        later_msg = env->query(arg+"/"+opt+"/later_msg");

// 這邊是設定如果被拿過了,就不會在出來了.(ps.理論上可行.)
// 房間於重生後將會重新set_temp("object")所以重生後才能在叫.


// 設定不能重覆拿的部份..
        mob=new(filename);

        if(ob_list){
        if(ob_list[filename] || !objectp(ob_list[filename])){
                destruct(mob);
                        write(env->query("action/"+opt+"/err_msg")+"\n");
                return 1;
        }
                ob_list +=  ([filename:mob]) ;
        } else ob_list =  ([filename:mob]) ;


// 傳出訊息...
        tell_object( this_player() , msg+"\n" );
        message_vision( before_msg+"\n" , this_player() ,mob);

// 把item 移到你的身上..

        mob->move(this_player());
        env->set_temp("clan_objects",ob_list);

// 顯示訊息...
        message_vision( later_msg+"\n" , this_player() ,mob );
        return 1;
}
void reset()
{
::reset();
// 在重生的時候,刪掉被人取過的temp...
   this_object()->delete_temp("clan_objects");
}
