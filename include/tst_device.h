/*
 * Copyright (c) 2016 Cyril Hrubis <chrubis@suse.cz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TST_DEVICE_H__
#define TST_DEVICE_H__

struct tst_device {
	const char *dev;
	const char *fs_type;
};

/*
 * Automatically initialized if test.needs_device is set.
 */
extern struct tst_device *tst_device;

/*
 * Just like umount() but retries several times on failure.
 * @path: Path to umount
 */
int tst_umount(const char *path);

/*
 * Clears a first few blocks of the device. This is needed when device has
 * already been formatted with a filesystems, subset of mkfs.foo utils aborts
 * the operation if it finds a filesystem signature there.
 *
 * Note that this is called from tst_mkfs() automatically, so you probably will
 * not need to use this from the test yourself.
 */
int tst_clear_device(const char *dev);

/*
 * Finds a free loop device for use and returns the free loopdev minor(-1 for no
 * free loopdev). If path is non-NULL, it will be filled with free loopdev path.
 *
 */
int tst_find_free_loopdev(const char *path, size_t path_len);
/*
 * Reads test block device stat file and returns the bytes written since the
 * last call of this function.
 * @dev: test block device
 */
unsigned long tst_dev_bytes_written(const char *dev);

#endif	/* TST_DEVICE_H__ */
