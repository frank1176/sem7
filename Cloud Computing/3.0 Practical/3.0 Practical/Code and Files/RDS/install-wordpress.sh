# Install WordPress on EC2 using RDS MySQL DB
# Either add "sudo" before all commands or use "sudo su" first
# Amazon Linux 2023

sudo su
dnf install php -y
dnf install php-mysqlnd -y
dnf install -y httpd
systemctl start httpd
systemctl enable httpd
cd /var/www/html
wget https://wordpress.org/latest.tar.gz 
tar -xzf latest.tar.gz
cp -r wordpress/* ./
chmod -R 755 wp-content
chown -R apache:apache wp-content
