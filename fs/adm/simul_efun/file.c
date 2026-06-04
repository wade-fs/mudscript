// file.c
int file_power(string file)
{
    object me;

    me=this_player();
    if(!me) me=previous_object();

    return SECURITY_D->valid_read(file,me);
}

void cat(string file, int trans)
{
  string tmp;
  int len,t1,t2,old_len;

  tmp = read_file(file);

  if (trans)
    tmp = trans_color(tmp);
  len=sizeof(tmp);
  old_len=len;
  if(len > 8000){
    t1=1;
    t2=0;
    while(len > 8000){
      write(tmp[(t2*8000)..((t1*8000)-1)]);
      len-=8000;
      t1++;
      t2++;
    }
    write(tmp[(t2*8000)..(old_len-1)]);
  }  else  
    write(tmp);
  tmp = 0;
}

void log_file(string file, string text)
{
        write_file(LOG_DIR + file, text);
}

void assure_file(string file)
{
        string path, *dir;
        int i;

        if( file_size(file)!=-1 ) return;

        seteuid(ROOT_UID);
        dir = explode(file, "/");
        dir = dir[0..sizeof(dir)-2];
        path = "/";
        for(i=0; i<sizeof(dir); i++) {
                path += dir[i];
                mkdir(path);
                path += "/";
        }
}

string base_name(object ob)
{
        string file;

        if( sscanf(file_name(ob), "%s#%*d", file)==2 )
                return file;
       else
                return file_name(ob);
}

int mkdirs(string path)
{
        string *parts, dir;
        int j;

        seteuid(geteuid(previous_object()));
        parts = explode(path, "/");
        dir = "";
        for (j = 0; j < sizeof(parts); j++) {
                dir += parts[j];
                mkdir(dir);
                dir += "/";
        }
        return (file_size(dir[0..<1]) == -2);
}

