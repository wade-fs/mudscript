// update.c
#include <ansi.h>
inherit F_CLEAN_UP;

int update_player(object me);
void update_dir(object me,string dir);
void update_all_object(object,string);
void check_file(string file);

int main(object me, string file)
{
        int i;
        object obj, tmp, *inv;
        string err;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("你要重新編譯什麼檔案﹖\n");
        "/adm/daemons/wizardd"->update_record(me->query("id"));
        if( (obj = present(file, environment(me))) && interactive(obj) )
                return update_player(obj);

        if( file == "me" )
                return update_player(me);
        if(sscanf(file,"-r %s",file) == 1)
        {
          file = resolve_path(me->query("cwd"),file);
          update_dir(me,file);
          write("更新 "+ file + "目錄完成！\n");
          return 1;
        }
        else if(sscanf(file,"-o %s",file) == 1)
        {
          file = resolve_path(me->query("cwd"),file);
          update_all_object(me,file);
          write("更新所有人的 "+ file + " 完成！\n");
          return 1;
        }
        else {
                file = resolve_path(me->query("cwd"), file);
                if( !sscanf(file, "%*s.c") ) file += ".c"; 
        }

        if( file_size(file)==-1 )
                return notify_fail("沒有這個檔案。\n");
        check_file(file);
        me->set("cwf", file);
  
        if (obj = find_object(file)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB && SECURITY_D->get_wiz_level(me)<7)
                                return notify_fail("你不能在 VOID_OB 裡重新編譯 VOID_OB。\n");
                        inv = all_inventory(obj);
                        i = sizeof(inv);
                        while(i--)
                                if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
//                              else destruct(inv[i]);
                }
                destruct(obj);
        }

        if (obj) return notify_fail("無法清除舊程式碼。\n");

        write("重新編譯 " + file + "﹕");
        err = catch( call_other(file, "???") );
        if (err)
                printf( "發生錯誤﹕\n%s\n", err );
        else {
                write("成功\﹗\n");
log_file("wiz/UPDATE", sprintf("%s(%s) 將%s的資料重新更新 %s\n"
,me->query("name"),me->query("id"),file, ctime(time()) ));
                if( (i=sizeof(inv)) && (obj = find_object(file))) {
                        while(i--) {
                                if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
                        }
                }
        }
        return 1;
}
void update_dir(object me,string dir)
{
  string file;
  string err;
  if(dir[strlen(dir)-1]!='/') dir += "/";
  write("編譯 "+dir+" 開始。\n");
  foreach( file in get_dir(dir) )
  {

    if(file[0] == '.') continue;
    if(file_size(dir+file) == -2) continue;

    if(find_object(dir+file)) {
      write("desturct "+dir+file+"\n");
      destruct(find_object(dir+file));
    }
    err = catch(call_other(dir+file,"???"));

    if(err) 
      write("編譯 "+dir+file+" 發生錯誤。\n");

  }
}
void update_all_object(object me ,string file)
{
  foreach(object obj in children(file))
  {
    object new_obj ,env;    
    if(!(env = environment(obj))) {
      destruct(obj);
      continue;
    }
    if(!obj) continue;   
    new_obj = new(file);

    destruct(obj);

    new_obj->move(env);
    if(env->is_character())
    {
      tell_object(env,sprintf("%s被一陣煙霧包圍，您身上的物品、武器或防具已經更新了，請檢查。\n",new_obj->name()));
      printf("%s身上的物件被更新了\n",env->short());
    }
  }
}

int update_player(object me)
{
        object env, link_ob, obj;

        env = environment(me);

        // First, create the new body.
        link_ob = me->query_temp("link_ob");
        obj = LOGIN_D->make_body(link_ob);
        if (!obj) return 0;

        // Save the data and exec the player to his/her link object.
        me->save();
        exec(link_ob, me);
        destruct(me);

        // Restore new body and exec to it via enter_world in LOGIN_D
        obj->restore();
        LOGIN_D->enter_world(link_ob, obj, 1);

        write("身體更新完畢。\n\n");
        obj->move(env);
        obj->write_prompt();
        log_file("wiz/UPDATE", sprintf("%s(%s) 將%s的身体重新更新 %s\n"
         ,me->query("name"),me->query("id"),obj, ctime(time()) ));
        return 1;
}
void check_file(string file)
{
  string str,*lines;
  str = read_file(file);
  lines = regexp(explode(str,"\n"),"query\\(\"(kar|str|con|cor|int|spi|per|cps)\"");
  if(sizeof(lines))
  {
    write(HIR"！！注意！！：\n"HIW);
    write(@DOC
        天賦取得方式已經更改，更改如下：
        query_kar()  => query_kar()
        query_str()  => query_str()
        query_con()  => query_con()
        query_int()  => query_int()
        query_spi()  => query_spi()
        query_per()  => query_per()
        query_cps()  => query_cps()
        query_cor()  => query_cor()


DOC
);
  }
}
int help(object me)
{
  write(@HELP
指令格式 : update [-r <目錄>] <檔名|here|me|玩家名>
 
這個指令可以更新檔案, 並將新檔的內容載入記憶體內. 若目標為
'here' 則更新所在環境. 若目標為 'me' 則更新自己的人物. 若目
標為玩家則可更新玩家物件.
使用 -r <目錄> 可以更新該目錄下所有檔案。
通常都使用 update -r . 來更新目前的目錄。
HELP
    );
    return 1;
}
 
