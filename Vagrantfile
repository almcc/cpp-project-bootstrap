Vagrant.configure("2") do |config|

  config.vm.box = "CentOS-6.5-x86_64"
  config.vm.box_url = "~/Development/environment/packer/CentOS-6.5-x86_64/CentOS-6.5.x86_64.box"

  # Global VM settings
  # ------------------------------

  config.vm.provider :virtualbox do |vb|
    vb.vm.gui = false
    vb.vm.customize ["modifyvm", :id, "--memory", "1024"]
    vb.vm.customize ["modifyvm", :id, "--cpus", 1]
  end

  # Puppet provisioning
  # ------------------------------

  config.vm.provision :puppet do |puppet|
    puppet.manifests_path = "~/Development/environment/puppet/manifests"
    puppet.manifest_file  = "site.pp"
    puppet.module_path = ["~/Development/environment/puppet/vendor",
                          "~/Development/environment/puppet/modules",]
  end

  # cppbootstrap VM
  # ------------------------------

  config.vm.define "cppbootstrap" do |cppbootstrap|
    cppbootstrap.vm.hostname = "cppbootstrap"
    cppbootstrap.vm.network :private_network, ip: "192.168.33.11"
    cppbootstrap.vm.synced_folder ".", "/home/vagrant/app"
  end

end
