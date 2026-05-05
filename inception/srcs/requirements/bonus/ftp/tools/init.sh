#!/bin/sh

FTP_PWD=$(cat /run/secrets/ftp_password)

if ! id "$FTP_USER" &>/dev/null; then
    adduser -D -h /var/www/html "$FTP_USER"
    echo "$FTP_USER:$FTP_PWD" | chpasswd
    
    echo "$FTP_USER" > /etc/vsftpd.userlist
fi

exec vsftpd /etc/vsftpd/vsftpd.conf
