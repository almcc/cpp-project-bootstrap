# Class: development
#
#
class development {
  package { 'make':
    ensure => installed,
  }
  package { 'gcc-c++':
    ensure => installed,
  }
  package { 'rpm-build':
    ensure => installed,
  }
  package { 'cppunit-devel':
    ensure => installed,
  }
  package { 'cppcheck':
    ensure => installed,
  }
  package { 'xmlrpc-c-devel':
    ensure => installed,
  }
  package { 'xmlrpc-c-apps':
    ensure => installed,
  }
  package { 'doxygen':
    ensure => installed,
  }
  package { 'graphviz':
    ensure => installed,
  }
  package { 'texlive-utils':
    ensure => installed,
  }
  package { 'texlive-latex':
    ensure => installed,
  }
  package { 'python-pip':
    ensure => installed,
  }
  package { 'tree':
    ensure => installed,
  }
  package { 'boost-devel':
    ensure => installed,
  }
  package { 'swig':
    ensure => installed,
  }
  package { 'python-devel':
    ensure => installed,
  }
  exec { 'sphinx':
    command => 'easy_install -U Sphinx',
    path    => [ '/usr/bin/' ],
  }
  exec { 'sphinx-bootstrap':
    command => 'pip install sphinx_bootstrap_theme',
    path    => [ '/usr/bin/' ],
    require => [Package['python-pip'], Exec['sphinx']]
  }
  exec { 'robotframework':
    command => 'pip install robotframework',
    path    => [ '/usr/bin/' ],
    require => Package['python-pip'],
  }
}