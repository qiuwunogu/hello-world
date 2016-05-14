/*
 * @dst:have enough space to save 'dir' and 'file'
 * @dir: directory path, not null
 * @file: filename, not null
 * platform: linux default. You can define PLATFORM_WINDOWS to use it on windows.
 */
char *utils_path_combination (char *dst, char *dir, char *file)
{
#ifdef PLATFORM_WINDOWS
  char split = '\';
#else //linux
  char split = '/';
#endif
  int dir_len = strlen (dir);
  
  if (dir[dir_len - 1] == split && file[0] == split)
    sprintf (dst, "%s %s", dir, file + 1);  
  else if (dir[dir_len - 1] != split && file[0] != split)
    sprintf (dst, "%s %c %s", dir, split,  file + 1);
  else
    sprintf (dst, "%s %s", dir, file);
	
  return dst;
}
