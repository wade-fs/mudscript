// arthurd.c
//
//      用來放不知道該放哪的 function
//
//                                              Created by Arthur

void create()
{
        seteuid(ROOT_UID);
}

// 用來刪除整個目錄, 包括目錄下的檔案
int remove_all_dir(string dir)
{
        mixed   *files;
        int     i;

        // 設定 euid
        seteuid(geteuid(previous_object()));

        if( dir[<0] != '/' )
                dir += "/";

        files   = get_dir(dir, -1);
        i       = sizeof(files);

        while(i--) 
        {
                // 目錄喔, 那就使用傳說中的遞回
                if( files[i][1] == -2 )
                        remove_all_dir( dir+files[i][0] );
                else 
                        rm( dir+files[i][0] );
        }
        rmdir(dir);
        return 1;
}
